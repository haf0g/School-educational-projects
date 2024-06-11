### Initialization and functions ###

# List of punctuation characters to remove
punctuation_chars = ["'", '"', ",", ".", "!", ":", ";", '#', '@']

# List of positive words
positive_words = []
with open("positive_words.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':  # Ignore comments and empty lines
            positive_words.append(lin.strip())

# List of negative words
negative_words = []
with open("negative_words.txt") as neg_f:
    for lin in neg_f:
        if lin[0] != ';' and lin[0] != '\n':  # Ignore comments and empty lines
            negative_words.append(lin.strip())

# Function to strip punctuation from a string
def strip_punctuation(string):
    """Removes any punctuation from the input string."""
    for item in punctuation_chars:
        if item in string:
            string = string.replace(item, '')
    return string

# Function to count positive words in a string
def get_pos(string):
    """Calculates how many words in the string are considered positive words."""
    string = strip_punctuation(string)
    string = string.lower().split()
    pos_count = 0
    for item in positive_words:
        if item in string:
            pos_count += 1
    return pos_count

# Function to count negative words in a string
def get_neg(string):
    """Calculates how many words in the string are considered negative words."""
    string = strip_punctuation(string)
    string = string.lower().split()
    neg_count = 0
    for item in negative_words:
        if item in string:
            neg_count += 1
    return neg_count

# Function to calculate net score (positive score - negative score)
def get_net(string):
    """Calculates the net score of the string (positive score - negative score)."""
    return get_pos(string) - get_neg(string)

### The real program starts here! ###

# Open input and output files
dataref = open("project_twitter_data.csv", 'r')
resulting_data = open('resulting_data.csv', 'w')

# Output the header row
resulting_data.write('Number of Retweets,Number of Replies,Positive Score,Negative Score,Net Score\n')

# Read and process each row in the input file
dataref_rows = []
for row in dataref:
    dataref_rows.append(row)
    
    # Skip the header row
    if row != dataref_rows[0]:
        resulting_data.write(
            '{},{},{},{},{}\n'.format(
                row.split(',')[1],  # Number of Retweets
                row.replace('\n', '').split(',')[2],  # Number of Replies
                get_pos(row.split(',')[0]),  # Positive Score
                get_neg(row.split(',')[0]),  # Negative Score
                get_net(row.split(',')[0])   # Net Score
            )
        )

# Close the files
dataref.close()
resulting_data.close()
