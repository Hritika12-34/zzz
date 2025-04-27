# Mapper function
def mapper(text):
    words = text.split()
    mapped = []
    for word in words:
        mapped.append((word.lower(), 1))  # (word, 1)
    return mapped

# Reducer function
def reducer(mapped_data):
    word_count = {}
    for word, count in mapped_data:
        if word in word_count:
            word_count[word] += count
        else:
            word_count[word] = count
    return word_count

# Input Text
text = "MapReduce is simple. MapReduce is powerful."

# Step 1: Map
mapped_data = mapper(text)

# Step 3: Reduce
word_count = reducer(mapped_data)

# Step 4: Display Output
for word, count in word_count.items():
    print(f"{word}: {count}")
