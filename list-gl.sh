#!/bin/sh
set -eu

DIR="${1:-.}"

rg --no-filename --pcre2 \
  -g'*.h' -g'*.c' -g'*.cc' \
  -o '\bgl[u]?[A-Za-z0-9_]+\s*\(' \
  "$DIR" \
| sed 's/[[:space:]]*(//' \
| sort -u