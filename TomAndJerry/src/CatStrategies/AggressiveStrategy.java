package CatStrategies;

import sample.DrawItems;
import sample.IBarrier;
import sample.MouseJerry;
import sample.Position;

import java.util.ArrayList;

/**
 * Created by katrin on 4/6/16.
 */
public class AggressiveStrategy implements Strategy {
    private static int dx[] = {-4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    private static int dy[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4};

    @Override
    public void Action(sample.CatTom cat, ArrayList<sample.DrawItems> items) {

        for (sample.DrawItems obj : items){
            if (obj instanceof sample.MouseJerry){
                forward((MouseJerry) obj, cat, items);
                break;
            }
        }
    }

    public  void forward(sample.MouseJerry mim, sample.CatTom cat, ArrayList<sample.DrawItems> items) {
        int curX = cat.getX();
        int curY = cat.getY();

        int bestX = curX;
        int bestY = curY;
        int bestDist = 10000;

        for (int j = 0; j < dx.length; j++) {
            int newx = dx[j] + curX;
            int newy = dy[j] + curY;

            if (cat.isFree(newx, newy, items) && mim.dist(mim.getX(), mim.getY(), newx, newy) <= bestDist) {
                bestX = newx;
                bestY = newy;
                bestDist = mim.dist(mim.getX(), mim.getY(), newx, newy);
            }
        }
        cat.change_picture(bestX, bestY);
        cat.setX(bestX);
        cat.setY(bestY);
    }
}
