alphabet = [['A','∴'], ['B', '∁'], ['C','∄'], ['D', '∩'],
            ['E', '¬'], ['F', '∆'], ['G', '↔'], ['H', '∋'],
            ['I', '∃'], ['J', '+'], ['L', '←'], ['M', '∈'],
            ['N', '∀'], ['Ñ', '≈'], ['O', '↑'], ['P', '∎'],
            ['Q', '↓'], ['R', '⋱'], ['S', '∅'], ['T', '∇'],
            ['U', '→'], ['V', '⋮'], ['X', '⋯'], ['Y', '≠'],
            ['Z', '~'], ['0', 'ᴁ'], ['1', 'ᵫ'], ['2', '⍾'],
            ['3', 'Ω'], ['4', '†'], ['5', '®'], ['6', 'Ψ'],
            ['7', 'Ѳ'], ['8', 'Ғ'], ['9', 'њ']]
output = ""
for i in range(7):
    s = input()
    for j in range(len(s)):
        a = True
        for k in range(len(alphabet)):
            if(s[j] == alphabet[k][1]):
                output = output + alphabet[k][0]
                a = False
        if(a):
            output = output + s[j]
    output = output + "\n"

print(output)