


### Initialisation and functions ###
punctuation_chars = ["'", '"', ",", ".", "!", ":", ";", '#', '@']
# lists of words to use
positive_words = []
with open("positive_words.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            positive_words.append(lin.strip())

negative_words = []
with open("negative_words.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            negative_words.append(lin.strip())
# Functions to use
def strip_punctuation(string):

    # It removes any sign of ponctuation
    # from the input string.

    for item in punctuation_chars:
        if item in string:
            string = string.replace(item ,'')
    return string

def get_pos(string):
    # takes one parameter, a string which represents one or more sentences
    # and calculates how many words
    # in the string are considered positive words
    string = strip_punctuation(string)
    string = string.lower().split()
    pos_count = 0
    for item in positive_words:
        if item in string:

            pos_count += 1
    return pos_count

def get_neg(string):
    # takes one parameter, a string which represents one or more sentences
    # and calculates how many words
    # in the string are considered negative words
    string = strip_punctuation(string)
    string = string.lower().split()
    pos_count = 0
    for item in negative_words:
        if item in string:
            pos_count += 1
    return pos_count

def get_net (string):
    return get_pos(string) - get_neg(string)


### The real program starts her !###
dataref = open("project_twitter_data.csv", 'r')
resulting_data = open('resulting_data.csv' ,'w')

# output the header row
resulting_data.write('Number of Retweets,Number of Replies,Positive Score,Negative Score,Net Score')
resulting_data.write('\n')
# output the columns :
dataref_rows = []
for row in dataref:

    dataref_rows.append(row)
    if row != dataref_rows[0]:
        resulting_data.write('{},{},{},{},{}\n'.format(row.split(',')[1],
                                                       row.replace('\n' ,'').split(',')[2],
                                                       get_pos(row.split(',')[0]),
                                                       get_neg(row.split(',')[0]),
                                                       get_net(row.split(',')[0])))

