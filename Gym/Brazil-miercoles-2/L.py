from math import sqrt
h, l = map(int, input().split())
h2 = h*h
l2 = l*l

szs =sqrt(((1.0*h2 + l2) * -1.0*((h2 + l2)/4.0))/(-h2)) - h

print("{0:.10f}".format(szs))