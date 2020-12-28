def anagramGroup(input):
    word_map = dict()
    for i in range(len(input)):
        sorted_word = "".join(sorted(input[i]))
        print(sorted_word)
        if sorted_word in word_map:
            word_map[sorted_word].append(i)
        else:
            word_map[sorted_word] = [i]

    res = []
    for word in word_map:
        for i in word_map[word]:
            res.append(input[i])
    return res



if __name__ == '__main__':
    input = ["abc", "def", "fed", "ghi", "cba"]
    res = anagramGroup(input)
    print(res)