text = "Branislav Blažek"
print(text[:])
print(text[2])
print(text[3:7])
print(text[:10])
print(text[8:])
print(text[::2])
print(text[::-3])
someText = ['ahoj', 'svet', 'vonku', 'je', 'pekne']
print(("/||\\").join(someText))
print(("/||\\").join(reversed(someText)))
print(text * 10)
t = "helloworld17"
print(t.capitalize())
print(t.center(50, "."))
print(t.count("o"))
print(t.endswith("rld"))
tab = "nazdar\tsvet"
print(tab.expandtabs(150))
print(t.isalnum())
print(tab.isalpha())
print("456789321".isdecimal())
print("456789321".isdigit())
print(t.isidentifier())
print(t.islower())
print("123456789".isnumeric())
print(text.isprintable())
print("   ".isspace())
print(text.istitle())
print("AHOJSVET".isupper())
print(text.ljust(50, "."))
print("CAPSLOCK".lower())
print(text.partition("lav"))
print(text.replace("B", "bBb", 3))
print(text.split("a"))
print(text.startswith("B"))
print("aaahojsvetaaaa".strip("a"))
print(text.swapcase())
print(t.title())
print(t.upper())
print(t.zfill(50))


