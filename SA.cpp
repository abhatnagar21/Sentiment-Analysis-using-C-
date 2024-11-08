#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;
void loadsentimentwords(unordered_map<string, int>& sentimentdict) {
    const string positivewords[] = {
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
    
    const string negativewords[] = {
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

    for (const auto& word : positivewords) {
        sentimentdict[word] = 1;
    }
    for (const auto& word : negativewords) {
        sentimentdict[word] = -1;
    }
}

// Helper function to remove punctuation from a word
string removepunctuation(const string& word) {
    string cleanedword;
    copy_if(word.begin(), word.end(), back_inserter(cleanedword), [](char c) {
        return !ispunct(c);
    });
    return cleanedword;
}

// Function to calculate the sentiment score of the input text
int analyzesentiment(const string& text, const unordered_map<string, int>& sentimentdict) {
    int sentimentscore = 0;
    string word;
    stringstream ss(text);

    // Process each word in the input text
    while (ss >> word) {
        // Convert word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        // Remove punctuation from the word
        word = removepunctuation(word);

        // Check if the cleaned word exists in the sentiment dictionary
        if (sentimentdict.count(word)) {
            sentimentscore += sentimentdict.at(word);
        }
    }
    
    return sentimentscore;
}

int main() {
    unordered_map<string, int> sentimentdict;
    loadsentimentwords(sentimentdict);
    
    string inputtext;
    cout << "Enter text for sentiment analysis: ";
    getline(cin, inputtext);

    if (inputtext.empty()) {
        cout << "No input provided." << endl;
        return 1;
    }

    int score = analyzesentiment(inputtext, sentimentdict);

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
