#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to load sentiment keywords into an unordered_map
void loadSentimentWords(unordered_map<string, int>& sentimentDict) {
    // Positive words with a score of +1
    const string positiveWords[] = {
        "excellent", "wonderful", "great", "fantastic", "amazing", "outstanding", 
        "superb", "brilliant", "terrific", "marvelous", "fabulous", "joyful", 
        "delightful", "positive", "happy", "cheerful", "perfect", "magnificent", 
        "lovely", "enjoyable", "admirable", "enthusiastic", "prosperous", 
        "grateful", "splendid", "incredible", "love", "appealing", "awesome", 
        "blissful", "bright", "commending", "compassionate", "courageous", 
        "encouraging", "elevated", "energetic", "engaging", "exquisite", 
        "flourishing", "generous", "graceful", "heartwarming", "inspiring", 
        "joyous", "luminous", "optimistic", "radiant", "reliable", 
        "satisfying", "spirited", "successful", "triumphant", "uplifting", 
        "vibrant", "wondrous"
    };
    
    // Negative words with a score of -1
    const string negativeWords[] = {
        "bad", "terrible", "awful", "horrible", "poor", "dreadful", 
        "disappointing", "unpleasant", "lousy", "atrocious", "subpar", 
        "inferior", "unsatisfactory", "regretful", "miserable", "pathetic", 
        "nasty", "deficient", "unfortunate", "sad", "depressed", "upset", 
        "frustrated", "angry", "annoyed", "distressed", "disheartened", 
        "discontented", "displeased", "fuming", "agitated", "desolate", 
        "bitter", "annoying", "apathetic", "bizarre", "clumsy", "dismal", 
        "dismaying", "dull", "frightening", "grim", "hopeless", "irritating", 
        "melancholic", "monotonous", "neglectful", "obnoxious", "repugnant", 
        "resentful", "shameful", "tedious", "troublesome", "unreliable", 
        "vexing", "worrisome", "worthless"
    };

    // Assign sentiment scores
    for (const auto& word : positiveWords) {
        sentimentDict[word] = 1;
    }
    for (const auto& word : negativeWords) {
        sentimentDict[word] = -1;
    }
}

// Helper function to remove punctuation from a word
string removePunctuation(const string& word) {
    string cleanedWord;
    copy_if(word.begin(), word.end(), back_inserter(cleanedWord), [](char c) {
        return !ispunct(c);
    });
    return cleanedWord;
}

// Function to calculate the sentiment score of the input text
int analyzeSentiment(const string& text, const unordered_map<string, int>& sentimentDict) {
    int sentimentScore = 0;
    string word;
    stringstream ss(text);

    // Process each word in the input text
    while (ss >> word) {
        // Convert word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        // Remove punctuation from the word
        word = removePunctuation(word);

        // Check if the cleaned word exists in the sentiment dictionary
        if (sentimentDict.count(word)) {
            sentimentScore += sentimentDict.at(word);
        }
    }
    
    return sentimentScore;
}

int main() {
    unordered_map<string, int> sentimentDict;
    loadSentimentWords(sentimentDict);
    
    string inputText;
    cout << "Enter text for sentiment analysis: ";
    getline(cin, inputText);

    if (inputText.empty()) {
        cout << "No input provided." << endl;
        return 1;
    }

    int score = analyzeSentiment(inputText, sentimentDict);

    cout << "Sentiment score: " << score << endl;

    if (score > 0) {
        cout << "The sentiment is Positive." << endl;
    } else if (score < 0) {
        cout << "The sentiment is Negative." << endl;
    } else {
        cout << "The sentiment is Neutral." << endl;
    }

    return 0;
}
