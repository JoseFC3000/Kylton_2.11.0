#pragma once
#ifndef ES_APP_FILE_FILTER_INDEX_H
#define ES_APP_FILE_FILTER_INDEX_H

#include <map>
#include <vector>
#include <string>

class FileData;

enum FilterIndexType
{
	NONE,
	GENRE_FILTER,
	PLAYER_FILTER,
	PUBLISHER_FILTER,
	DEVELOPER_FILTER,
	FULLSYSTEM_FILTER,
	REGION_FILTER,
	RATINGS_FILTER,
	FAVORITES_FILTER,
	HIDDEN_FILTER,
	KIDGAME_FILTER
};

struct FilterDataDecl
{
	FilterIndexType type; // type of filter
	std::map<std::string, int>* allIndexKeys; // all possible filters for this type
	bool* filteredByRef; // is it filtered by this type
	std::vector<std::string>* currentFilteredKeys; // current keys being filtered for
	std::string primaryKey; // primary key in metadata
	bool hasSecondaryKey; // has secondary key for comparison
	std::string secondaryKey; // what's the secondary key
	std::string menuLabel; // text to show in menu
};

class FileFilterIndex
{
public:
	FileFilterIndex();
	~FileFilterIndex();
	void addToIndex(FileData* game);
	void removeFromIndex(FileData* game);
	void setFilter(FilterIndexType type, std::vector<std::string>* values);
	void clearAllFilters();
	void debugPrintIndexes();
	bool showFile(FileData* game);
	bool isFiltered() { return (filterByGenre || filterByPlayers || filterByPublisher || filterByDeveloper || filterByFullSystem || filterByRegion || filterByRatings || filterByFavorites || filterByHidden || filterByKidGame); };
	bool isKeyBeingFilteredBy(std::string key, FilterIndexType type);
	std::vector<FilterDataDecl>& getFilterDataDecls();

	void importIndex(FileFilterIndex* indexToImport);
	void resetIndex();
	void resetFilters();
	void setUIModeFilters();

private:
	std::vector<FilterDataDecl> filterDataDecl;
	std::string getIndexableKey(FileData* game, FilterIndexType type, bool getSecondary);

	void manageGenreEntryInIndex(FileData* game, bool remove = false);
	void managePlayerEntryInIndex(FileData* game, bool remove = false);
	void managePublisherEntryInIndex(FileData* game, bool remove = false);
	void manageDeveloperEntryInIndex(FileData* game, bool remove = false);
	void manageFullSystemEntryInIndex(FileData* game, bool remove = false);
	void manageRegionEntryInIndex(FileData* game, bool remove = false);
	void manageRatingsEntryInIndex(FileData* game, bool remove = false);
	void manageFavoritesEntryInIndex(FileData* game, bool remove = false);
	void manageHiddenEntryInIndex(FileData* game, bool remove = false);
	void manageKidGameEntryInIndex(FileData* game, bool remove = false);

	void manageIndexEntry(std::map<std::string, int>* index, std::string key, bool remove);

	void clearIndex(std::map<std::string, int> indexMap);

	bool filterByGenre;
	bool filterByPlayers;
	bool filterByPublisher;
	bool filterByDeveloper;
	bool filterByFullSystem;
	bool filterByRegion;
	bool filterByRatings;
	bool filterByFavorites;
	bool filterByHidden;
	bool filterByKidGame;

	std::map<std::string, int> genreIndexAllKeys;
	std::map<std::string, int> playersIndexAllKeys;
	std::map<std::string, int> publisherIndexAllKeys;
	std::map<std::string, int> developerIndexAllKeys;
	std::map<std::string, int> fullsystemIndexAllKeys;
	std::map<std::string, int> regionIndexAllKeys;
	std::map<std::string, int> ratingsIndexAllKeys;
	std::map<std::string, int> favoritesIndexAllKeys;
	std::map<std::string, int> hiddenIndexAllKeys;
	std::map<std::string, int> kidGameIndexAllKeys;

	std::vector<std::string> genreIndexFilteredKeys;
	std::vector<std::string> playersIndexFilteredKeys;
	std::vector<std::string> publisherIndexFilteredKeys;
	std::vector<std::string> developerIndexFilteredKeys;
	std::vector<std::string> fullsystemIndexFilteredKeys;
	std::vector<std::string> regionIndexFilteredKeys;
	std::vector<std::string> ratingsIndexFilteredKeys;
	std::vector<std::string> favoritesIndexFilteredKeys;
	std::vector<std::string> hiddenIndexFilteredKeys;
	std::vector<std::string> kidGameIndexFilteredKeys;

	FileData* mRootFolder;

};

#endif // ES_APP_FILE_FILTER_INDEX_H
