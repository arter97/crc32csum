# crc32csum

A simple utility for calculating crc32c from pipe or files using arm64 or x86 instructions.

## Disclaimer

#### ● arm64 code's author: Wei Xiao(https://github.com/axboe/fio/blob/master/crc/crc32c-arm64.c)

#### ● x86 and software implementation code's author: Mark Adler(https://github.com/madler/brotli/blob/master/crc32c.c)

## Compiling

### ● x86

```
gcc -msse4.2 -Wall -O3 -o crc32csum crc32csum.c
```

### ● arm64

```
gcc -march=armv8-a+crc+crypto -Wall -O3 -o crc32csum crc32csum.c
```

## Benchmarks

1 GiB file from /dev/urandom was placed under tmpfs ramdisk before each runs.

x86: Intel Core i7-8550U

arm64: OnePlus 7 Pro (Snapdragon 855)

crc32 utility was from libarchive-zip-perl.

### ● x86

| Utility       | Version | Speed         |
| ------------- | ------- | ------------- |
| **crc32csum** | N/A     | 6059.17 MiB/s |
| crc32         | 1.60-1  | 1088.20 MiB/s |
| xxh128sum     | 0.7.3   | 6606.45 MiB/s |
| xxh64sum      | 0.7.3   | 5953.49 MiB/s |
| xxh32sum      | 0.7.3   | 4338.98 MiB/s |
| md5sum        | 8.28    |  655.15 MiB/s |
| sha1sum       | 8.28    |  586.82 MiB/s |
| sha256sum     | 8.28    |  227.86 MiB/s |
| sha512sum     | 8.28    |  372.09 MiB/s |

### ● arm64

| Utility       | Version | Speed         |
| ------------- | ------- | ------------- |
| **crc32csum** | N/A     | 2892.66 MiB/s |
| crc32         | 1.60-1  |  605.56 MiB/s |
| xxh128sum     | 0.7.3   | 2645.99 MiB/s |
| xxh64sum      | 0.7.3   | 1812.39 MiB/s |
| xxh32sum      | 0.7.3   | 2221.26 MiB/s |
| md5sum        | 8.28    |  395.98 MiB/s |
| sha1sum       | 8.28    |  417.11 MiB/s |
| sha256sum     | 8.28    |  237.42 MiB/s |
| sha512sum     | 8.28    |  320.40 MiB/s |

## Enjoy!
