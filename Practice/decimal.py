try:
    from _decimal import *
    from _decimal import __doc__
    from _decimal import __version__
    from _decimal import __libmpdec_version__
except ImportError:
    from _pydecimal import *
    from _pydecimal import __doc__
    from _pydecimal import __version__
    from _pydecimal import __libmpdec_version__


def fractionToDecimal(numerator: int, denominator: int) -> str:
    getcontext().prec = 10**4 + 1
    n = Decimal(numerator) / Decimal(denominator)
    print
    s = str(n)
    i = 0
    while s[i] != ".":
        i += 1
    point = i+1
    if len(s) != 10**4 + point + 2:
        return s
    i += 1
    repeat = "" + s[i]
    while repeat != s[i+1:i + 1 + len(repeat)] and i+1 < i + 1 + len(repeat):
        i += 1
        repeat = repeat + s[i]
    ss = s[0:point] + "(" + repeat + ")"
    return ss

print(fractionToDecimal(1,2))
print(fractionToDecimal(4,333))
print(fractionToDecimal(1,5))