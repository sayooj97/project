from nltk.tokenize import sent_tokenize
# nltk.download("punkt")

def split_comment(comment):
    """Split comment into smaller sentences."""
    return sent_tokenize(comment)

# Example
comment = "My RTX 3080 crashes often, but my Ryzen 9 is fantastic!"
print(split_comment(comment))
