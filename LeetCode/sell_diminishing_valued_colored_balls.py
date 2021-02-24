class Solution(object):
    def maxProfit(self, inventory, orders):
        inventory.sort(reverse=True)
        inventory.append(0)
        ran = 0
        i = 0
        ans = 0
        while orders > 0:
            ran += 1
            sold = min(orders, ran *  (inventory[i] - inventory[i + 1]))
            whole, rem = divmod(sold, ran)
            ans += ran * (whole * (inventory[i] + inventory[i] - (whole - 1)) // 2) + rem * (inventory[i] - whole)
            orders -= sold
            i += 1
        return ans % (10 ** 9 + 7)

# Time limit exceeded
class Solution1(object):
    def maxProfit(self, inventory, orders):
        inventory.sort(reverse=True)
        ran = 1
        res = 0
        while orders > 0:
            if ran == len(inventory):
                count = orders // ran
                orders -= count * ran
                for i in range(inventory[0], inventory[0] - count, -1):
                    res += i * ran
                inventory[0] -= count
                res += inventory[0] * orders
                break
                
            ran = min(orders, ran)
            res += inventory[0] * ran
            inventory[0] -= 1
            orders -= ran
            if ran < len(inventory) and inventory[0] == inventory[ran]:
                ran += 1
        return res % (10 ** 9 + 7)