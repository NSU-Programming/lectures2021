import json

def fibb():
    a, b = 1, 1
    yield a
    yield b
    while True:
        a, b = b, a + b
        yield b

def make_numbers():
    fgen = fibb()
    with open('numbers.txt', 'w') as ofile:
        for _ in range(20):
            ofile.write(f'{next(fgen)} ')

def process_cities_json(ifname, ofname):
    with open(ifname) as ifile:
        data = json.loads(ifile.read())

    print(f'{len(data)} cities')
    with open(ofname, 'w') as ofile:
        for item in data:
            if not item['population']:
                continue
            name = item["city"]
            lookup = {
                b'\xd0\x93\xd1\x98': b'u',
                b'\xd0\x93\xc2\xa4': b'a',
                b'\xd0\x93\xc2\xb6': b'o',
            }
            for key, value in lookup.items():
                name = name.encode().replace(key, value).decode()
            ofile.write(f'"{name}" ({item["lat"]}, {item["lng"]}) {item["population"]}\n')

if __name__ == '__main__':
    # make_numbers()
    for lbl in ['ru', 'de']:
        process_cities_json(f'data/{lbl}.json', f'data/{lbl}.txt')
