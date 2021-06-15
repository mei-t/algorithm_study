class Solution:
    def prisonAfterNDays(self, cells, n):
        all_cells = [cells]
        cells_dict = {tuple(cells): 0}
        for i in range(1, n + 1):
            res = [0] * 8
            for j in range(1, 7):
                if cells[j - 1] == cells[j + 1]:
                    res[j] = 1
            
            if tuple(res) in cells_dict:
                idx = cells_dict[tuple(res)]
                return all_cells[idx + (n - idx) % (i - idx)]
            all_cells.append(res)
            cells_dict[tuple(res)] = i
            cells = res
        
        return res

class Solution2:
    def prisonAfterNDays(self, cells, n):
        bitmap = 0x0
        for cell in cells:
            bitmap <<= 1
            bitmap |= cell
        print(bitmap)
        all_cells = [bitmap]
        cells_dict = {bitmap: 0}
        for i in range(1, n + 1):
            res = ~ ((bitmap << 1) ^ (bitmap >> 1))
            res &= 0x7e
            if res in cells_dict:
                idx = cells_dict[res]
                res = all_cells[idx + (n - idx) % (i - idx)]
                break
            all_cells.append(res)
            cells_dict[res] = i
            bitmap = res
        
        ans = []
        for _ in range(8):
            ans.append(res & 1)
            res >>= 1
        return reversed(ans)
        