{
    'targets': [{
        'target_name': 'ictclas',
        'sources': ['./ictclas.cc'],
        "include_dirs": [
            "include", "./lib", "<!(node -e \"require('nan')\")"
        ],
        'libraries': [
            '/home/liz/GitLab/ICTCLAS/lib/libNLPIR.so',
        ],
        "cflags": ["-Wall -Wunused -O3 -DOS_LINUX"]
    }]
}
