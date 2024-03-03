//Made by Adamski. 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to generate a random role excluding already assigned roles
string generateRandomRole(const vector<string>& assignedRoles) {
    vector<string> roles = { "Toplane", "Midlane", "Botlane", "Support", "Jungle" };

    // Remove assigned roles from the available roles
    for (const auto& assignedRole : assignedRoles) {
        roles.erase(remove(roles.begin(), roles.end(), assignedRole), roles.end());
    }

    if (roles.empty()) {
        // All roles have been assigned, return an empty string
        return "";
    }

    int randomIndex = rand() % roles.size();
    return roles[randomIndex];
}

// Function to generate a random champion based on the role excluding already assigned champions
string generateRandomChampion(const string& role, const vector<string>& assignedChampions) {
    // Replace these lists with your actual lists of champions per role
    vector<string> toplaneChampions = { "Aatrox", "Akali", "Akshan", "Briar", "Camille", "Cassiopeia", "Cho'Gath", "Darius", "Dr. Mundo", "Fiora", "Gangplank", "Garen", "Gnar", "Gragas", "Gwen", "Heimerdinger", "Illaoi", "Irelia", "Jarvan IV", "Jax", "Jayce", "Karma", "Kayle", "Kennen", "Kled", "K'Sante", "Malphite", "Mordekaiser", "Naafiri", "Nasus", "Olaf", "Ornn", "Pantheon", "Poppy", "Quinn", "Renekton", "Rengar", "Riven", "Rumble", "Ryze", "Sett", "Shen", "Singed", "Sion", "Smolder", "Swain", "Sylas", "Tahm Kench", "Teemo", "Trundle", "Tryndamere", "Twisted Fate", "Udyr", "Urgot", "Vayne", "Vladimir", "Volibear", "Warwick", "Wukong", "Yasuo", "Yone", "Yorick", "Zac" };
    vector<string> midlaneChampions = { "Ahri", "Akali", "Akshan", "Anivia", "Annie", "Aurelion Sol", "Azir", "Brand", "Cassiopeia", "Cho'Gath", "Corki", "Diana", "Ekko", "Fizz", "Galio", "Gangplank", "Gragas", "Heimerdinger", "Hwei", "Irelia", "Karma", "Kassadin", "Katarina", "Kennen", "LeBlanc", "Lissandra", "Lux", "Malphite", "Malzahar", "Naafiri","Neeko", "Orianna", "Pantheon", "Quinn", "Renekton", "Rumble", "Ryze","Smolder", "Swain", "Sylas", "Syndra", "Taliyah", "Talon", "Tristana","Twisted Fate", "Veigar", "Vel'Koz", "Vex", "Viktor", "Vladimir", "Xerath", "Yasuo", "Yone", "Zed", "Ziggs", "Zoe" };
    vector<string> botlaneChampions = { "Aphelios", "Ashe", "Aurelion Sol", "Caitlyn", "Cassiopeia", "Draven", "Ezreal", "Heimerdinger", "Jhin", "Jinx", "Kai'Sa", "Kalista", "Karthus", "Kog'Maw", "Lucian", "Miss Fortune", "Nilah", "Samira", "Senna", "Seraphine", "Sivir", "Smolder", "Swain", "Tahm Kench", "Tristana", "Twisted Fate", "Twitch", "Varus", "Vayne", "Veigar", "Xayah", "Yasuo", "Zeri", "Ziggs" };
    vector<string> supportChampions = { "Alistar", "Amumu", "Anivia", "Annie", "Ashe", "Bard", "Blitzcrank", "Brand", "Braum", "Camille", "Fiddlesticks", "Galio", "Heimerdinger", "Hwei", "Ivern", "Janna", "Karma", "LeBlanc", "Leona", "Lulu", "Lux", "Maokai", "Milio", "Morgana", "Nami", "Nautilus", "Neeko", "Pantheon", "Poppy", "Pyke", "Rakan", "Rell", "Renata Glasc", "Senna", "Seraphine", "Shaco", "Shen", "Sona", "Soraka", "Swain", "Tahm Kench", "Taric", "Thresh", "Twitch", "Veigar", "Vel'Koz", "Xerath", "Yuumi", "Zilean","Zyra" };
    vector<string> jungleChampions = { "Amumu", "Bel'Veth", "Brand", "Briar", "Diana", "Ekko", "Elise", "Evelynn", "Fiddlesticks", "Gragas", "Graves", "Gwen", "Hecarim", "Ivern", "Jarvan IV", "Jax", "Karthus", "Kayn", "Kha'Zix", "Kindred", "Lee Sin", "Lillia", "Maokai", "Master Yi", "Nidalee", "Nocturne", "Nunu & Willump", "Poppy", "Qiyana", "Rammus", "Rek'Sai", "Rell", "Rengar", "Rumble", "Sejuani", "Shaco", "Shyvana", "Skarner", "Taliyah", "Talon", "Teemo", "Trundle", "Udyr", "Vi", "Viego", "Volibear", "Warwick", "Wukong", "Xin Zhao", "Zac", "Zed", "Zyra" };

    vector<string> availableChampions;

    // Choose the appropriate champion list based on the role
    if (role == "Toplane") {
        availableChampions = toplaneChampions;
    }
    else if (role == "Midlane") {
        availableChampions = midlaneChampions;
    }
    else if (role == "Botlane") {
        availableChampions = botlaneChampions;
    }
    else if (role == "Support") {
        availableChampions = supportChampions;
    }
    else if (role == "Jungle") {
        availableChampions = jungleChampions;
    }

    // Remove assigned champions from the available champions
    for (const auto& assignedChampion : assignedChampions) {
        availableChampions.erase(remove(availableChampions.begin(), availableChampions.end(), assignedChampion), availableChampions.end());
    }

    if (availableChampions.empty()) {
        // All champions for the given role have been assigned, return an empty string
        return "";
    }

    int randomIndex = rand() % availableChampions.size();
    return availableChampions[randomIndex];
}

int main() {
    srand(time(0));

    // Ask the user for the number of players (max 5)
    int numberOfPlayers;
    cout << "Enter the number of players (max 5): ";
    cin >> numberOfPlayers;

    // Check that the number of players is between 1 and 5
    if (numberOfPlayers < 1 || numberOfPlayers > 5) {
        cout << "Invalid number of players. Exiting the program." << endl;
        return 1;
    }

    // Create vectors to store assigned roles and champions
    vector<string> assignedRoles;
    vector<string> assignedChampions;

    // Let each player enter their name
    vector<string> playerNames;
    for (int i = 0; i < numberOfPlayers; ++i) {
        string playerName;
        cout << "Enter the name for player " << i + 1 << ": ";
        cin >> playerName;
        playerNames.push_back(playerName);
    }

    // Clear the console screen
    system("cls");

    // Generate a random role and champion for each player
    for (const auto& playerName : playerNames) {
        string randomRole = generateRandomRole(assignedRoles);
        if (randomRole.empty()) {
            cout << "All roles have been assigned. Exiting the program." << endl;
            return 1;
        }

        string randomChampion = generateRandomChampion(randomRole, assignedChampions);
        if (randomChampion.empty()) {
            cout << "All champions for the role '" << randomRole << "' have been assigned. Exiting the program." << endl;
            return 1;
        }

        // Store the assigned role and champion in the vectors
        assignedRoles.push_back(randomRole);
        assignedChampions.push_back(randomChampion);
    }

    // Display the results for each player
    for (size_t i = 0; i < playerNames.size(); ++i) {
        cout << playerNames[i] << " has the role: " << assignedRoles[i] << " and plays as: " << assignedChampions[i] << endl;

    }

    cout << "\nPress Enter to exit..";
    cin.ignore(); //ignore any previous newline character
    cin.get(); // wait for user to press enter

    return 0;
}




/*vector<string> toplaneChampions = { "Aatrox", "Akali", "Akshan", "Briar", "Camille", "Cassiopeia", "Cho'Gath", "Darius", "Dr. Mundo", "Fiora", "Gangplank", "Garen", "Gnar", "Gragas", "Gwen", "Heimerdinger", "Illaoi", "Irelia", "Jarvan IV", "Jax", "Jayce", "Karma", "Kayle", "Kennen", "Kled", "K'Sante", "Malphite", "Mordekaiser", "Naafiri", "Nasus", "Olaf", "Ornn", "Pantheon", "Poppy", "Quinn", "Renekton", "Rengar", "Riven", "Rumble", "Ryze", "Sett", "Shen", "Singed", "Sion", "Smolder", "Swain", "Sylas", "Tahm Kench", "Teemo", "Trundle", "Tryndamere", "Twisted Fate", "Udyr", "Urgot", "Vayne", "Vladimir", "Volibear", "Warwick", "Wukong", "Yasuo", "Yone", "Yorick", "Zac" };
    vector<string> midlaneChampions = { "Ahri", "Akali", "Akshan", "Anivia", "Annie", "Aurelion Sol", "Azir", "Brand", "Cassiopeia", "Cho'Gath", "Corki", "Diana", "Ekko", "Fizz", "Galio", "Gangplank", "Gragas", "Heimerdinger", "Hwei", "Irelia", "Karma", "Kassadin", "Katarina", "Kennen", "LeBlanc", "Lissandra", "Lux", "Malphite", "Malzahar", "Naafiri","Neeko", "Orianna", "Pantheon", "Quinn", "Renekton", "Rumble", "Ryze","Smolder", "Swain", "Sylas", "Syndra", "Taliyah", "Talon", "Tristana","Twisted Fate", "Veigar", "Vel'Koz", "Vex", "Viktor", "Vladimir", "Xerath", "Yasuo", "Yone", "Zed", "Ziggs", "Zoe" };
    vector<string> botlaneChampions = { "Aphelios", "Ashe", "Aurelion Sol", "Caitlyn", "Cassiopeia", "Draven", "Ezreal", "Heimerdinger", "Jhin", "Jinx", "Kai'Sa", "Kalista", "Karthus", "Kog'Maw", "Lucian", "Miss Fortune", "Nilah", "Samira", "Senna", "Seraphine", "Sivir", "Smolder", "Swain", "Tahm Kench", "Tristana", "Twisted Fate", "Twitch", "Varus", "Vayne", "Veigar", "Xayah", "Yasuo", "Zeri", "Ziggs" };
    vector<string> supportChampions = { "Alistar", "Amumu", "Anivia", "Annie", "Ashe", "Bard", "Blitzcrank", "Brand", "Braum", "Camille", "Fiddlesticks", "Galio", "Heimerdinger", "Hwei", "Ivern", "Janna", "Karma", "LeBlanc", "Leona", "Lulu", "Lux", "Maokai", "Milio", "Morgana", "Nami", "Nautilus", "Neeko", "Pantheon", "Poppy", "Pyke", "Rakan", "Rell", "Renata Glasc", "Senna", "Seraphine", "Shaco", "Shen", "Sona", "Soraka", "Swain", "Tahm Kench", "Taric", "Thresh", "Twitch", "Veigar", "Vel'Koz", "Xerath", "Yuumi", "Zilean","Zyra" };
    vector<string> JungleChampions =  { "Amumu", "Bel'Veth", "Brand", "Briar", "Diana", "Ekko", "Elise", "Evelynn", "Fiddlesticks", "Gragas", "Graves", "Gwen", "Hecarim", "Ivern", "Jarvan IV", "Jax", "Karthus", "Kayn", "Kha'Zix", "Kindred", "Lee Sin", "Lillia", "Maokai", "Master Yi", "Nidalee", "Nocturne", "Nunu & Willump", "Poppy", "Qiyana", "Rammus", "Rek'Sai", "Rell", "Rengar", "Rumble", "Sejuani", "Shaco", "Shyvana", "Skarner", "Taliyah", "Talon", "Teemo", "Trundle", "Udyr", "Vi", "Viego", "Volibear", "Warwick", "Wukong", "Xin Zhao", "Zac", "Zed", "Zyra" };
*/

// BOTLANE
//vector<string> champions = { "Aphelios", "Ashe", "Aurelion Sol", "Caitlyn", "Cassiopeia", "Draven", "Ezreal", "Heimerdinger", "Jhin", "Jinx", "Kai'Sa", "Kalista", "Karthus", "Kog'Maw", "Lucian", "Miss Fortune", "Nilah", "Samira", "Senna", "Seraphine", "Sivir", "Smolder", "Swain", "Tahm Kench", "Tristana", "Twisted Fate", "Twitch", "Varus", "Vayne", "Veigar", "Xayah", "Yasuo", "Zeri", "Ziggs" };

// TOPLANE
//vector<string> champions = { "Aatrox", "Akali", "Akshan", "Briar", "Camille", "Cassiopeia", "Cho'Gath", "Darius", "Dr. Mundo", "Fiora", "Gangplank", "Garen", "Gnar", "Gragas", "Gwen", "Heimerdinger", "Illaoi", "Irelia", "Jarvan IV", "Jax", "Jayce", "Karma", "Kayle", "Kennen", "Kled", "K'Sante", "Malphite", "Mordekaiser", "Naafiri", "Nasus", "Olaf", "Ornn", "Pantheon", "Poppy", "Quinn", "Renekton", "Rengar", "Riven", "Rumble", "Ryze", "Sett", "Shen", "Singed", "Sion", "Smolder", "Swain", "Sylas", "Tahm Kench", "Teemo", "Trundle", "Tryndamere", "Twisted Fate", "Udyr", "Urgot", "Vayne", "Vladimir", "Volibear", "Warwick", "Wukong", "Yasuo", "Yone", "Yorick", "Zac" };

// JUNGLE
//vector<string> champions = { "Amumu", "Bel'Veth", "Brand", "Briar", "Diana", "Ekko", "Elise", "Evelynn", "Fiddlesticks", "Gragas", "Graves", "Gwen", "Hecarim", "Ivern", "Jarvan IV", "Jax", "Karthus", "Kayn", "Kha'Zix", "Kindred", "Lee Sin", "Lillia", "Maokai", "Master Yi", "Nidalee", "Nocturne", "Nunu & Willump", "Poppy", "Qiyana", "Rammus", "Rek'Sai", "Rell", "Rengar", "Rumble", "Sejuani", "Shaco", "Shyvana", "Skarner", "Taliyah", "Talon", "Teemo", "Trundle", "Udyr", "Vi", "Viego", "Volibear", "Warwick", "Wukong", "Xin Zhao", "Zac", "Zed", "Zyra" };

// MIDLANE
//vector<string> champions = { "Ahri", "Akali", "Akshan", "Anivia", "Annie", "Aurelion Sol", "Azir", "Brand", "Cassiopeia", "Cho'Gath", "Corki", "Diana", "Ekko", "Fizz", "Galio", "Gangplank", "Gragas", "Heimerdinger", "Hwei", "Irelia", "Karma", "Kassadin", "Katarina", "Kennen", "LeBlanc", "Lissandra", "Lux", "Malphite", "Malzahar", "Naafiri","Neeko", "Orianna", "Pantheon", "Quinn", "Renekton", "Rumble", "Ryze","Smolder", "Swain", "Sylas", "Syndra", "Taliyah", "Talon", "Tristana","Twisted Fate", "Veigar", "Vel'Koz", "Vex", "Viktor", "Vladimir", "Xerath", "Yasuo", "Yone", "Zed", "Ziggs", "Zoe" };

// SUPPORT
//vector<string> champions = { "Alistar", "Amumu", "Anivia", "Annie", "Ashe", "Bard", "Blitzcrank", "Brand", "Braum", "Camille", "Fiddlesticks", "Galio", "Heimerdinger", "Hwei", "Ivern", "Janna", "Karma", "LeBlanc", "Leona", "Lulu", "Lux", "Maokai", "Milio", "Morgana", "Nami", "Nautilus", "Neeko", "Pantheon", "Poppy", "Pyke", "Rakan", "Rell", "Renata Glasc", "Senna", "Seraphine", "Shaco", "Shen", "Sona", "Soraka", "Swain", "Tahm Kench", "Taric", "Thresh", "Twitch", "Veigar", "Vel'Koz", "Xerath", "Yuumi", "Zilean","Zyra" };