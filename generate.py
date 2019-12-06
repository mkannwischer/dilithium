import re
import os
import fileinput
import shutil
import subprocess
import glob
from contextlib import suppress

PQCLEAN_PATH = '../PQClean-dilithium/'

files = {
    'ref': [
        'params.h',
        'api.h',
        'ntt.c',
        'ntt.h',
        'packing.c',
        'packing.h',
        'poly.c',
        'poly.h',
        'polyvec.c',
        'polyvec.h',
        'reduce.c',
        'reduce.h',
        'rounding.c',
        'rounding.h',
        'sign.c',
        'sign.h',
        'stream.c',
        'stream.h',
        'symmetric.h',
        'Makefile',
        'Makefile.Microsoft_nmake',
        'LICENSE',
    ],
    'avx2': [
        'alignment.h',
        'api.h',
        'fips202x4.c',
        'fips202x4.h',
        'invntt.s',
        'nttconsts.c',
        'nttconsts.h',
        'ntt.h',
        'ntt.s',
        'packing.c',
        'packing.h',
        'params.h',
        'pointwise.S',
        'poly.c',
        'poly.h',
        'polyvec.c',
        'polyvec.h',
        'reduce.h',
        'reduce.s',
        'rejsample.c',
        'rejsample.h',
        'rounding.c',
        'rounding.h',
        'shuffle.inc',
        'sign.c',
        'sign.h',
        'stream.c',
        'stream.h',
        'symmetric.h',
        'Makefile',
        'LICENSE',
    ]
}


# Change me to generate a different namespace.
def generate_namespace(variant, impl):
    return f"PQCLEAN_{variant}_{impl}_".upper()


def replace_in_file(path, text_to_search, replacement_text):
    with fileinput.FileInput(path, inplace=True) as file:
        for line in file:
            print(re.sub(text_to_search, replacement_text, line), end='')


def unifdef(path, params, defs, undefs=None):
    if undefs is None:
        undefs = []
    subprocess.run([
        'unifdef',
        '-m',
        *[f'-D{name}={val}' if val else '-Dname'
          for name, val in defs.items()],
        '-f', params,
        *[f'-U{name}' for name in undefs],
        path
    ])


def astyle(*paths):
    subprocess.check_output(
        ['astyle',
         f'--options={PQCLEAN_PATH}/.astylerc',
         *paths])


SCHEMES = {
    'dilithium3': {
        'src': 'ref',
        'dst': 'clean',
        'defs': {
            'MODE': '3',
        },
        'undefs': [
            'NIST_COMPATIBLE',
            'USE_AES',
        ],
    },
    'dilithium2': {
        'src': 'ref',
        'dst': 'clean',
        'defs': {
            'MODE': '2',
        },
        'undefs': [
            'NIST_COMPATIBLE',
            'USE_AES',
        ],
    },
    'dilithium4': {
        'src': 'ref',
        'dst': 'clean',
        'defs': {
            'MODE': '4',
        },
        'undefs': [
            'NIST_COMPATIBLE',
            'USE_AES',
        ],
    },
    # Cheat duplicate keys via spaces
    'dilithium3 ': {
        'src': 'avx2',
        'dst': 'avx2',
        'defs': {
            'MODE': '3',
        },
        'undefs': [
            'NIST_COMPATIBLE',
            'USE_AES',
        ],
    },
}

for name, options in SCHEMES.items():
    name = name.strip()
    namespace = generate_namespace(name, options['dst'])
    srcpath = os.path.join('.', options['src'])
    implpath = os.path.join(PQCLEAN_PATH, 'crypto_sign', name, options['dst'])
    print(f"Generating {implpath}")

    shutil.rmtree(implpath, ignore_errors=True)
    with suppress(OSError):
        os.makedirs(implpath)

    for file in files[options['src']]:
        target = os.path.join(implpath, file)
        shutil.copyfile(os.path.join(srcpath, file), target)
        replace_in_file(target, 'DILITHIUM_', namespace)
        if file not in ['Makefile', 'Makefile.Microsoft_nmake', 'LICENSE']:
            unifdef(target, os.path.join('params', f'{name}.h'),
                    options['defs'], options['undefs'])
    replace_in_file(
        os.path.join(implpath, 'Makefile'),
        'libdilithium3_clean', f'lib{name}_{options["dst"]}')
    if 'Makefile.Microsoft_nmake' in files[options['src']]:
        replace_in_file(
            os.path.join(implpath, 'Makefile.Microsoft_nmake'),
            'libdilithium3_clean', f'lib{name}_{options["dst"]}')

    subprocess.run([
        'clang-tidy', '-fix-errors', '-quiet', '-header-filter=.*',
        *[os.path.join(implpath, file)
          for file in files[options['src']]
          if file[-2:] in ('.c', '*.h')],
        '--',
        '-iquote', os.path.join(PQCLEAN_PATH, 'common'),
        '-iquote', implpath,
    ], capture_output=True)
    srcs = [os.path.join(implpath, file)
            for file in files[options['src']]
            if file[-2:] in ('.c', '.h')]
    astyle(*srcs)
