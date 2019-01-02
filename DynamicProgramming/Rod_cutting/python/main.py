def cutting_rod(array_prices, length):
    optimal_prices = [0] * length

    for i in range(0, length, 1):
        # print(optimal_prices)
        price = 0
        cut = [0]
        if i < len(array_prices):
            price = array_prices[i]
            cut = [i + 1]
        for j in range(1, min(i, len(array_prices)), 1):
            # print(i, j)
            # print("\n", optimal_prices[i - j])
            temp_price, temp_cut = optimal_prices[i - j]
            temp_price += array_prices[j - 1]
            # print(array_prices[j])
            if temp_price > price:
                price = temp_price
                # print(temp_cut)
                # print("temp cut", temp_cut)
                cut = temp_cut.copy()
                cut.append(j)
            # print("cut", cut)
        # print(cut)
        optimal_prices[i] = (price, cut)


    return optimal_prices[length - 1]

if __name__ == "__main__":
    prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
    for i in range(1,30):
        print(i,cutting_rod(prices, i))
