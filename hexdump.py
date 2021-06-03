from io import StringIO


def print_mem_view(args):
    s = '|'
    for i in args:
        if ord(i) >= 0x20 and ord(i) <= 0x7E:
            character = i.decode('ascii')
        else:
            character = '.'
        s += character
    alignment = 17 - len(s)
    s += '.' * alignment
    s += '|'
    return s


def dump_file(filename):
    address = 0
    line = []
    with open(filename, 'rb') as file:
        file.seek(0)
        while True:
            if len(line) < 16:
                byte = file.read(1)
                if not byte:
                    break
                line.append(byte)
            else:
                output = ' '.join([
                    '0x{:08x}'.format(address),
                    ' '.join('{:02x}'.format(ord(b)) for b in line[:8]),
                    ' ', 
                    ' '.join('{:02x}'.format(ord(b)) for b in line[8:]),
                    print_mem_view(line)])
                print(output)
                line.clear()
                address += 0x10

    if len(line) > 0:
        spaces = ' ' * (((16 - len(line)) * 3) - 1)
        if spaces == '':
            output = ' '.join([
                    '0x{:08x}'.format(address),
                    ' '.join('{:02x}'.format(ord(b)) for b in line[:8]),
                    ' ', 
                    ' '.join('{:02x}'.format(ord(b)) for b in line[8:]),
                    print_mem_view(line)])        
        else:
            output = ' '.join([
                    '0x{:08x}'.format(address),
                    ' '.join('{:02x}'.format(ord(b)) for b in line[:8]),
                    ' ', 
                    ' '.join('{:02x}'.format(ord(b)) for b in line[8:]),
                    spaces,
                    print_mem_view(line)])        
        print(output)


if __name__ == '__main__':
    fname = 'games\\tetris.gb'

    dump_file(fname)