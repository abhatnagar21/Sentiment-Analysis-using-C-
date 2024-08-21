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
    sentimentDict["excellent"] = 1;
    sentimentDict["wonderful"] = 1;
    sentimentDict["great"] = 1;
    sentimentDict["fantastic"] = 1;
    sentimentDict["amazing"] = 1;
    sentimentDict["outstanding"] = 1;
    sentimentDict["superb"] = 1;
    sentimentDict["brilliant"] = 1;
    sentimentDict["terrific"] = 1;
    sentimentDict["marvelous"] = 1;
    sentimentDict["fabulous"] = 1;
    sentimentDict["joyful"] = 1;
    sentimentDict["delightful"] = 1;
    sentimentDict["positive"] = 1;
    sentimentDict["happy"] = 1;
    sentimentDict["cheerful"] = 1;
    sentimentDict["perfect"] = 1;
    sentimentDict["magnificent"] = 1;
    sentimentDict["lovely"] = 1;
    sentimentDict["enjoyable"] = 1;
    sentimentDict["admirable"] = 1;
    sentimentDict["enthusiastic"] = 1;
    sentimentDict["prosperous"] = 1;
    sentimentDict["grateful"] = 1;
    sentimentDict["splendid"] = 1;
    sentimentDict["incredible"] = 1;

    // Negative words with a score of -1
    sentimentDict["bad"] = -1;
    sentimentDict["terrible"] = -1;
    sentimentDict["awful"] = -1;
    sentimentDict["horrible"] = -1;
    sentimentDict["poor"] = -1;
    sentimentDict["dreadful"] = -1;
    sentimentDict["disappointing"] = -1;
    sentimentDict["unpleasant"] = -1;
    sentimentDict["lousy"] = -1;
    sentimentDict["atrocious"] = -1;
    sentimentDict["subpar"] = -1;
    sentimentDict["inferior"] = -1;
    sentimentDict["unsatisfactory"] = -1;
    sentimentDict["regretful"] = -1;
    sentimentDict["miserable"] = -1;
    sentimentDict["pathetic"] = -1;
    sentimentDict["nasty"] = -1;
    sentimentDict["deficient"] = -1;
    sentimentDict["unfortunate"] = -1;
    sentimentDict["sad"] = -1;
    sentimentDict["depressed"] = -1;
    sentimentDict["upset"] = -1;
    sentimentDict["frustrated"] = -1;
    sentimentDict["angry"] = -1;
    sentimentDict["annoyed"] = -1;
    sentimentDict["distressed"] = -1;
    sentimentDict["disheartened"] = -1;
    sentimentDict["discontented"] = -1;
    sentimentDict["displeased"] = -1;
    sentimentDict["fuming"] = -1;
    sentimentDict["agitated"] = -1;
    sentimentDict["desolate"] = -1;
    sentimentDict["bitter"] = -1;
}

// Helper function to remove punctuation from a word
string removePunctuation(const string& word) {
    string cleanedWord;
    for (char c : word) {
        if (!ispunct(c)) {
            cleanedWord += c;
        }
    }
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
        if (sentimentDict.find(word) != sentimentDict.end()) {
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
