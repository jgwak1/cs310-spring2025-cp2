#include "TVShow.h"
#include "FavoriteTVShows.h"

using namespace std;


int main() {
    FavoriteTVShows favorites;

    unsigned int count, capacity;

    // Initial capacity before adding any shows
    cout << "\nInitial capacity before expansion:\n";
    favorites.getSizes(count, capacity, true);

    // Test ADDITIVE Expansion
    cout << "\nSetting policy to ADDITIVE (increase by 3 slots per expansion):\n";
    if (favorites.setExpansionPolicy(Policy::ADDITIVE, 3)) {
        cout << "Policy successfully set to ADDITIVE.\n";
    } else {
        cout << "Failed to set policy.\n";
    }

    // Adding shows to trigger expansion
    cout << "\nAdding TV Shows with ADDITIVE expansion policy...\n";
    for (int i = 1; i <= 7; i++) { // Add enough to trigger at least one expansion
        favorites.getSizes(count, capacity, true); // Print size before expansion

        string name = "Show " + to_string(i);
        TVShow show(name, 2000 + i, "Network " + to_string(i), "Company " + to_string(i), i * 10);
        favorites.store(show);

        favorites.getSizes(count, capacity, true); // Print size after expansion
    }

    // Test MULTIPLICATIVE Expansion
    cout << "\nSetting policy to MULTIPLICATIVE (triple size per expansion):\n";
    if (favorites.setExpansionPolicy(Policy::MULTIPLICATIVE, 3)) {
        cout << "Policy successfully set to MULTIPLICATIVE.\n";
    } else {
        cout << "Failed to set policy.\n";
    }

    // Adding more shows to trigger expansion under MULTIPLICATIVE policy
    cout << "\nAdding more TV Shows with MULTIPLICATIVE expansion policy...\n";
    for (int i = 8; i <= 15; i++) { // Add enough to trigger at least one expansion
        favorites.getSizes(count, capacity, true); // Print size before expansion

        string name = "Show " + to_string(i);
        TVShow show(name, 2000 + i, "Network " + to_string(i), "Company " + to_string(i), i * 10);
        favorites.store(show);

        favorites.getSizes(count, capacity, true); // Print size after expansion
    }

    // Final display of all stored shows
    cout << "\nFinal List of Stored TV Shows:\n";
    favorites.display();

    // **Test Copy Constructor**
    cout << "\nTesting Copy Constructor (creating copy of favorites)...\n";
    FavoriteTVShows favoritesCopy = favorites;
    favoritesCopy.display();

    // Modify the original and check if the copy remains unchanged
    cout << "\nRemoving 'Show 5' from the original container...\n";
    favorites.remove("Show 5");

    cout << "\nOriginal after removal:\n";
    favorites.display();
    
    cout << "\nCopied version should still have 'Show 5':\n";
    favoritesCopy.display(); // If deep copy works, Show 5 should still be here

    // Test Copy Assignment Operator
    cout << "\nTesting Copy Assignment Operator...\n";
    FavoriteTVShows favoritesAssigned;
    favoritesAssigned = favorites; // Assign from the modified 'favorites'

    cout << "\nAssigned version (should match modified original, not the copy):\n";
    favoritesAssigned.display();

    return 0;
}
