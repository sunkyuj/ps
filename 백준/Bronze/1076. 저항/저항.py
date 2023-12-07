sn = ""
mp = {
    "black"	:0,
    "brown"	:1,
    "red"	:2,
    "orange":3,
    "yellow":4,
    "green"	:5,
    "blue"	:6,
    "violet":7,
    "grey"	:8,
    "white"	:9
}
sn += str(mp[input()])
sn += str(mp[input()])
print(int(sn)*10**mp[input()])