import json

with open("a.json", "r") as txt:
    data = json.loads(txt.read())


    for atom in data:
        symbol = '"'+atom["symbol"]+'"'
        x = str(atom["xpos"]-1)
        y = str(atom["ypos"]-1)

        print("{", f'{symbol:4}, {x:2}, {y}', "},")