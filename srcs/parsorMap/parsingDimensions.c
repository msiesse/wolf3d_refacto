#include "parsorMap.h"

void	launchParsingOfDimensions(ParsorDataStocker *parsorStockerAddr, FileReader *reader) {
	ignoreCommentsAndEmptyLines(reader);
	parsorStockerAddr->numberOfRows = getNumberOfRows(reader);
	ignoreCommentsAndEmptyLines(reader);
	parsorStockerAddr->numberOfColumns = getNumberOfColumns(reader);
}