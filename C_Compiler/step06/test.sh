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
# step3
assert 41 " 12 + 34 - 5 "
# step5
assert 47 '5+6*7'
assert 15 '5*(9-6)'
assert 4 '(3+5)/2'
# sterp6
assert 10 '-10+20'
assert 10 '- -10'
assert 10 '- - +10'

# [ success ]
echo OK