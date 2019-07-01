#include "VisitorDrawHeat.h"

void VisitorDrawHeat::visit(DataSet *dataset, Boundaries *boundaries)
{

	// for (DataPointIterator it = dataset->begin(); it != dataset->end(); ++it)
	// {
	// 	driver->drawPixel((*it).projectDataPoint(boundaries));
	// }

	// for (int px = 0; px < (this->width / HEATMAP_PIXEL_SIZE); px++)
	// 	{
	// 		for (int py = 0; py < (this->height / HEATMAP_PIXEL_SIZE); py++)
	// 		{
	// 			/* Compute pixel value */
	// 			float pixelValue = 0.0;

	// 			for (int idx = 0; idx < dataX.size; idx++)
	// 			{

	// 				int cellX = int(PlotMath::floatMap(dataX.dataset[idx], range.xMin, range.xMax, 0, this->width / HEATMAP_PIXEL_SIZE));
	// 				int cellY = int(PlotMath::floatMap(dataY.dataset[idx], range.yMin, range.yMax, 0, this->height / HEATMAP_PIXEL_SIZE));

	// 				float distX = pow(px - cellX, 2);
	// 				float distY = pow(py - cellY, 2);
	// 				float distance = sqrt(distX + distY);
	// 				pixelValue += (1.0 / (distance + 1.0));
	// 			}

	// 			if (pixelValue > maxValue)
	// 				maxValue = pixelValue;
	// 		}
	// 	}

	// 	/* for each 'pixel' compute its value depending on the distance from each point */
	// 	/* for speed issue, the pixel size can be increased */
	// 	for (int px = 0; px < (this->width / HEATMAP_PIXEL_SIZE); px++)
	// 	{
	// 		for (int py = 0; py < (this->height / HEATMAP_PIXEL_SIZE); py++)
	// 		{
	// 			/* Compute pixel value */
	// 			float pixelValue = 0.0;

	// 			for (int idx = 0; idx < dataX.size; idx++)
	// 			{

	// 				int cellX = int(PlotMath::floatMap(dataX.dataset[idx], range.xMin, range.xMax, 0, this->width / HEATMAP_PIXEL_SIZE));
	// 				int cellY = int(PlotMath::floatMap(dataY.dataset[idx], range.yMin, range.yMax, 0, this->height / HEATMAP_PIXEL_SIZE));

	// 				float distX = pow(px - cellX, 2);
	// 				float distY = pow(py - cellY, 2);
	// 				float distance = sqrt(distX + distY);
	// 				pixelValue += (1.0 / (distance + 1.0));
	// 			}
	// 			/* Normalize pixelValue */
	// 			/* If all dataset point are in the same point, the max value is dataSize*/
	// 			pixelValue = pixelValue / maxValue;

	// 			float r, g, b;
	// 			int dataX1 = normalizeX(px, 0, (this->width / HEATMAP_PIXEL_SIZE));
	// 			int dataX2 = normalizeX(px + 1, 0, (this->width / HEATMAP_PIXEL_SIZE));

	// 			int dataY1 = normalizeY(py, 0, (this->height / HEATMAP_PIXEL_SIZE));
	// 			int dataY2 = normalizeY(py + 1, 0, (this->height / HEATMAP_PIXEL_SIZE));

	// 			PlotColor_t pixelColor;
	// 			cs->getHeatmapColor(pixelValue, pixelColor);
	// 			tft->fillRect(dataX1, dataY1, dataX2 - dataX1, dataY2 - dataY1, ColorUtils::colorTo16b(pixelColor));
	// 		}
	// 	}
}

