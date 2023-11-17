def producto_cruz(a, b):
    return a[0]*b[1] - a[1]*b[0]


def sol():
    points = list(map(int, input().split()))

    points = [[points[0], points[1]], [points[2], points[3]], [points[4], points[5]]]

    dx = [0, -1, 1, 0]
    dy = [-1, 0, 0, 1]

    lengths = []
    for i in range(3):
        for j in range(i + 1,3):
            lengths.append((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1]) ** 2)
    lengths.sort()
    if lengths[0] + lengths[1] == lengths[2]:
        print("RIGHT")
        return

    for k in range(4):
        for i in range(3):
            lengths = []
            x = points[i][0] + dx[k]
            y = points[i][1] + dy[k]
            p = False
            # if producto_cruz([x, y], points[(i + 1) % 3]) == 0 and producto_cruz(points[(i + 1) % 3], points[(i + 2) % 3]) == 0:
            #     continue
            for j in range(3):
                if i == j:
                    continue
                lengths.append((x - points[j][0])**2 + (y - points[j][1]) ** 2)
            if p:
                continue
            lengths.append((points[(i + 1) % 3][0] - points[(i + 2) % 3][0])**2 + (points[(i + 1) % 3][1] - points[(i + 2) % 3][1]) ** 2)
            lengths.sort()
            if lengths[0] == 0:
                continue
            if lengths[0] + lengths[1] == lengths[2]:
                print("ALMOST")
                return
    print("NEITHER")

sol()
