s = input()
while s != '0':
    planes, n, m = map(int, s.split())

    grid = [[] for _ in range(n)]

    for i in range(n):
        grid[i] = input().split()

    plane_order = input().split()

    solution = {}

    parking = []

    landing = []

    parkingPosition = {}

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '==':
                landing.append((i, j))
            elif grid[i][j] != '..' and grid[i][j] != '##':
                parking.append(grid[i][j])
                parkingPosition[grid[i][j]] = (i, j)

    def dfs(visited, i, j, fi, fj):
        if i == fi and j == fj:
            return True
        diri = [-1, 0, 0, 1]
        dirj = [0, -1, 1, 0]
        visited[i][j] = True
        for k in range(4):
            ni = i + diri[k]
            nj = j + dirj[k]
            if ni > -1 and ni < n and nj > -1 and nj < m and grid[ni][nj] != '##' and not visited[ni][nj]:
                if dfs(visited, ni, nj, fi, fj):
                    return True
        return False

    def sol(pI):
        if pI == len(plane_order):
            return True
        plane_num = int(plane_order[pI][1:])
        if plane_order[i][0] == '+':
            
            possible_parking = []
            for land in landing:
                landI, landJ = land
                for park in parking:
                    parkI, parkJ = parkingPosition[park]
                    visited = [[False for _ in range(m)] for __ in range(n)]
                    if dfs(visited, landI, landJ, parkI, parkJ):
                        possible_parking.append(park)
            for possible_park in possible_parking:
                
                parkI, parkJ = parkingPosition[possible_park]
                grid[parkI][parkJ] = '##'
                solution[plane_num] = possible_park
                if sol(pI + 1):
                    return True
                solution[plane_num] = "-1"
                grid[parkI][parkJ] = possible_parking
            return False
        else:
            park_spot = solution[plane_num]
            parkI, parkJ = parkingPosition[park_spot]
            for land in landing:
                landI, landJ = land
                visited = [[False for _ in range(m)] for __ in range(n)]
                if dfs(visited, parkI, parkJ, landI, landJ):
                    grid[parkI][parkJ] = park_spot
                    if sol(pI + 1):
                        return True
                    grid[parkI][parkJ] = '##'
            return False


    if sol(0):
        print("YES")
        ans = []
        for val in solution.values():
            ans.append(val)
        print(" ".join(ans))
    else:
        print("NO")
    s = input()

