class MorseCode:
    __morse_code = {
        'A': '.-',
        'B': '-...',
        'C': '-.-.',
        'D': '-..',
        'E': '.',
        'F': '..-.',
        'G': '--.',
        'H': '....',
        'I': '..',
        'J': '.---',
        'K': '-.-',
        'L': '.-..',
        'M': '--',
        'N': '-.',
        'O': '---',
        'P': '.--.',
        'Q': '--.-',
        'R': '.-.',
        'S': '...',
        'T': '-',
        'U': '..-',
        'V': '...-',
        'W': '.--',
        'X': '-..-',
        'Y': '-.--',
        'Z': '--..',
        ' ': ' '
    }

    def coding(self, string):
        morse_code = ""
        for character in string:
            morse_code += self.__morse_code[character.upper()]
            morse_code += " "
        return morse_code[0:len(morse_code)-1]


morseCode = MorseCode()
print(morseCode.coding("Hello word"))
