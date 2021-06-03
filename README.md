
# This project is an introduction to cryptographic hashing algorithms

<ul><li>This prorgamm is my project as a part of the of the security branch at [42 Silicon Valley](https://www.42.us.org)</li></ul>
<ul><li>The goal was to recreate part of the [OpenSSL](https://en.wikipedia.org/wiki/OpenSSL) functionality</li></ul>

## Implemented Hash Functions

* [MD5](https://en.wikipedia.org/wiki/MD5)
* [SHA224](https://en.wikipedia.org/wiki/SHA-2)
* [SHA256](https://en.wikipedia.org/wiki/SHA-2)
* [SHA384](https://en.wikipedia.org/wiki/Secure_Hash_Algorithms)
* [SHA512](https://en.wikipedia.org/wiki/SHA-2)


## How to use?

1. In terminal excecute <code>git clone https://github.com/agusev/my_cryptographic_hashin_algorithms.git</code>
2. To build, in terminal excecute <code>make</code>

2. To launch, in terminal excecute <code>./ft_ssl command [command opts] [command args]</code>`


## Usage

* command:
    <code>md5</code>`
    <code>sha224</code>`
    <code>sha256</code>`
    `sha384`
    `sha512`
    
* command opts: `[-pqr] [-s string] [files ...]`

    >-p, echo STDIN to STDOUT and append the checksum to STDOUT

    >-q, quiet mode

    >-r, reverse the format of the output

    >-s, print the sum of the given string


## Examples

`./ft_ssl md5 -s "Hello World"`

MD5 ("Hello World") = b10a8db164e0754105b7a99be72e3fe5


`echo "Some important message" | ./ft_ssl sha256 -p -s "Hello World" Makefile`

Some important message

31d1104978e7f73a0da6375f1b0d9add90bf96fbc5ef4dc9fb16804697ef2894

SHA256("Hello World")= a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e

SHA256(Makefile)= 8f959d6ccc1e4127677099b0a0f99f85cf97e232eccc1def7c13e7437c2d9b2e
