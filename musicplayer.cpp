#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define SIZE 20
1
int song_op = 0, lang_op = 0, genre_op = 0, fav_op = 0;
string lang_ch;

struct song {
    string name;
    string genre;
    string lang;
    string singer;
    string movie;
};

struct operations {
    string name;
    string lang;
};

vector<song> s(SIZE);
vector<operations> head_his;
vector<operations> head_fav;

void display_songs() {
    cout << "\n\t******************************\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\t" << i + 1 << "->" << s[i].name << "\n";
    }
    cout << "\t******************************\n";
}

void history(int index) {
    operations newnode;
    newnode.name = s[index].name;
    newnode.lang = s[index].lang;
    head_his.push_back(newnode);
}

void display_history() {
    cout << "History:\n";
    for (int i = 0; i < head_his.size(); i++) {
        cout << i + 1 << "->" << head_his[i].name << "\n";
    }
}

int size_his() {
    return head_his.size();
}

void del_in_his(int index) {
    if (index > 0 && index <= size_his()) {
        cout << "Deleted song from history: " << head_his[index - 1].name << "\n";
        head_his.erase(head_his.begin() + index - 1);
    } else {
        cout << "Invalid option.\n";
    }
}

void Delete_history() {
    head_his.clear();
    cout << "History is Successfully Deleted...\n";
}

void add_to_fav(int index) {
    if (index > 0 && index <= SIZE) {
        operations newnode;
        newnode.name = s[index - 1].name;
        newnode.lang = s[index - 1].lang;
        head_fav.push_back(newnode);
        cout << "Added song to favorites: " << s[index - 1].name << "\n";
    } else {
        cout << "Invalid option.\n";
    }
}

int size_fav() {
    return head_fav.size();
}

void del_in_fav(int index) {
    if (index > 0 && index <= size_fav()) {
        cout << "Deleted song from favorites: " << head_fav[index - 1].name << "\n";
        head_fav.erase(head_fav.begin() + index - 1);
    } else {
        cout << "Invalid option.\n";
    }
}

void display_fav() {
    cout << "Favorites:\n";
    for (int i = 0; i < head_fav.size(); i++) {
        cout << i + 1 << "->" << head_fav[i].name << "\n";
    }
}

void sort_by_lang(const string& str) {
    cout << "Displaying " << str << " songs:\n";
    for (int i = 0; i < SIZE; i++) {
        if (str == s[i].lang) {
            cout << s[i].name << "\n";
        }
    }
}

void display_details(int opt) {
    if (opt > 0 && opt <= SIZE) {
        cout << "Song Name: " << s[opt - 1].name << "\n";
        cout << "Movie Name: " << s[opt - 1].movie << "\n";
        cout << "Genre: " << s[opt - 1].genre << "\n";
        cout << "Language: " << s[opt - 1].lang << "\n";
        cout << "Singer: " << s[opt - 1].singer << "\n";
    } else {
        cout << "Invalid option.\n";
    }
}

void sort_by_genre(const string& str) {
    cout << "Songs of " << str << " genre:\n";
    for (int i = 0; i < SIZE; i++) {
        if (str == s[i].genre) {
            cout << s[i].name << "\n";
        }
    }
}

int main() {
    int ch;
    lang_ch = "";
    s[0] = {"Bekhayali", "sad", "Hindi", "Sanchet Tandon", "Kabir singh"};
    s[1] = {"Spirit of Jersey", "inspirational", "Telugu", "Kala Bhairava", "Jersey"};
    s[2] = {"Adiga Adiga", "Romantic", "Telugu", "Sid Sriram", "Ninnu Kori"};
    s[3] = {"Jaamurathri", "90's Hits", "Telugu", "s.p.Bala subramanyam sir", "Kshana Kshanam"};
    s[4] = {"Pilla Raa", "Romantic", "Telugu", "Chaitan Bhardwaj", "RX 100"};
    s[5] = {"Bheemla Naayak Title song", "pop", "Telugu", "Thaman.s", "Bheemla Nayak"};
    s[6] = {"Apna Time Aayaga", "pop", "Hindi", "Dub sharma", "Gully Boy"};
    s[7] = {"Mein Tera Boy Friend", "Hit song", "Hindi", "RAABTA", "Pritan, Arjit singh"};
    s[8] = {"Kadhal Psycho", "pop", "Tamil", "Anirudh Ravichandar", "Saaho"};
    s[9] = {"Ennai Vuttu", "party", "Tamil", "Ranjith govind", "Kanulu Kanulanu Dochayantay"};
    s[10] = {"Neeyum Naamum Anbe", "romantic", "Tamil", "Raghu Dixit", "Imaikkaa Nodigal"};
    s[11] = {"Kanna Veesi Kanna Veesi", "romantic", "Tamil", "Rahul Hariharan", "Kadhal Ondru Kanden"};
    s[12] = {"Bllood Bath", "party", "Tamil", "Arunraga Kamaraj", "Asuran"};
    s[13] = {"Yaanjai", "party", "Tamil", "Anirudh Ravi Chandra", "Vikram Vedha"};
    s[14] = {"Yaar indha saalai", "pop", "Tamil", "G.V.Prakash kumar", "Thalaiva"};
    s[15] = {"Jab tak", "party", "Hindi", "Armaan Malik", "M.S.dhoni"};
    s[16] = {"Khairiyat", "party", "Hindi", "arijit singh", "chhichhore"};
    s[17] = {"Raabta Title song", "pop", "Hindi", "arijit singh", "Raabta"};
    s[18] = {"Dil Bechara", "inspirational", "Hindi", "A.R.rahman", "Dil Bachara"};
    s[19] = {"Love Is A Waste Of Time", "Hit song", "Hindi", "Shreya Ghoshal", "p.k"};

    while (true) {
        cout << "\n 1. Play a song \n 2. Display history\n 3. Delete a song from history \n 4. Delete History\n 5. Favourites \n"
            " 6. Displaying favourites\n 7. Sort by language \n 8. Display details \n 9. Sort by Genre\n 10. Exit ";
        cout << "\n\n Choose an option->";
        cin >> ch;
        switch (ch) {
            case 1:
                display_songs();
                cout << "\n\n Choose a song -> ";
                cin >> song_op;
                if (song_op > 0 && song_op <= SIZE) {
                    cout << "\n Playing song " << s[song_op - 1].name << "...\n";
                    history(song_op - 1);
                } else {
                    cout << "\n The option is invalid\n";
                }
                break;
            case 2:
                display_history();
                break;
            case 3:
                if (head_his.empty()) {
                    cout << "No history\n";
                } else {
                    display_history();
                    cout << " Choose a song to delete from history: ";
                    cin >> song_op;
                    del_in_his(song_op);
                }
                break;
            case 4:
                Delete_history();
                break;
            case 5:
                cout << "\n 1. Add to Favourites\n 2. Delete a song from Favourites\n 3. Delete favourites";
                cout << "\n\n Choose an option : ";
                cin >> fav_op;
                if (fav_op == 1) {
                    display_songs();
                    cout << "\n Choose a song to add to favourites: ";
                    cin >> song_op;
                    add_to_fav(song_op);
                } else if (fav_op == 2) {
                    if (!head_fav.empty()) {
                        cout << "Displaying favorites:\n";
                        display_fav();
                        cout << "\n Choose a song to delete from favourites: ";
                        cin >> song_op;
                        del_in_fav(song_op);
                    } else {
                        cout << "There are no songs in the favorites\n";
                    }
                } else if (fav_op == 3) {
                    head_fav.clear();
                    cout << "No favorites\n";
                }
                break;
            case 6:
                display_fav();
                break;
            case 7:
                cout << "\n 1. Telugu \n 2. Tamil \n 3. Hindi";
                cout << "\n Choose your language: ";
                cin >> lang_op;
                if (lang_op == 1) {
                    lang_ch = "Telugu";
                } else if (lang_op == 2) {
                    lang_ch = "Tamil";
                } else if (lang_op == 3) {
                    lang_ch = "Hindi";
                }
                sort_by_lang(lang_ch);
                break;
            case 8:
                display_songs();
                cout << " Choose a song to display the details of the song: ";
                cin >> song_op;
                display_details(song_op);
                break;
            case 9:
                cout << "\n 1. Sad \n 2. Inspirational \n 3. Romantic \n 4. 90's Hits \n 5. Pop \n 6. Hit song \n 7. Party";
                cout << "\n Choose the genre of a song: ";
                cin >> genre_op;
                if (genre_op == 1) {
                    lang_ch = "sad";
                } else if (genre_op == 2) {
                    lang_ch = "inspirational";
                } else if (genre_op == 3) {
                    lang_ch = "Romantic";
                } else if (genre_op == 4) {
                    lang_ch = "90's Hits";
                } else if (genre_op == 5) {
                    lang_ch = "pop";
                } else if (genre_op == 6) {
                    lang_ch = "Hit song";
                } else if (genre_op == 7) {
                    lang_ch = "party";
                }
                sort_by_genre(lang_ch);
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}
