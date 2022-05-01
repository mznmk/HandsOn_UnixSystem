#!/bin/bash

# [ assert function ]
assert()
{
    expected="$1"
    input="$2"

    # [ execute script ]
    ./9cc "$input" > tmp.s
    cc tmp.s -o tmp
    ./tmp
    actual="$?"

    # [ compare ]
    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}

# [ test ]
# step1
assert 0 0
assert 42 42
# step2
assert 21 "5+20-4"

# [ success ]
echo OK