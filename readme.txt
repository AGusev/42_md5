# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readme.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:55:51 by agusev            #+#    #+#              #
#    Updated: 2019/04/04 22:25:00 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ft_ssl_md5
recreating md5, sha256 and sha 256 algorithms


## Project
FT_SSL_MD5 is a 42 Project that mimics libc ls function

* Basic functions:
1) md5, sha256

* Flags:
1) -s, -q, -r -p

* Bonus:
1) sha256

## Sources
* https://en.wikipedia.org/wiki/SHA-2
* https://en.wikipedia.org/wiki/MD5
* https://csrc.nist.gov/csrc/media/publications/fips/180/4/final/documents/fips180-4-draft-aug2014.pdf

## Installation
```
$> make
$> ./ft_ssl_md5 {hash_function} {flag} {file}
$> works with stdin too:
$> 1)./ft_ssl_md5 {hash_function}
$> 2) Hit Enter, enter text, ctrl + d to output
```
