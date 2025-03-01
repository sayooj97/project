import pandas as pd
import google.generativai as genai

gneai.configure(api_keys = 'AIzaSyBnJPhIy8E9gzrQkHObiRmRtuooOk_05k0')
df = pd.read("reddit_comments.csv")

def analyze_sentiment(review_text):
    model = genai.GenerativeModel("gemini-1.5-flash")
     prompt = f"""
     Analyze the senimtent of this produt comments and classify it as:
        -postive
        -negative
        -neutaral

        review: "{review_text}"

        only reutrn one word as outuput( postive, neutral, or negative)
        """
    response =model.generate_content(prompt)
    return response.text.strip()

df["sentimet"] = df["comment"].apply(lambda review: analyze_sentiment(str(review)))