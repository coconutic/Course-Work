package CatStrategies;

import sample.CatTom;
import sample.Constants;
import sample.DrawItems;

import java.util.ArrayList;

/**
 * Created by katrin on 4/6/16.
 */
public class FearStrategy implements Strategy {

    @Override
    public void Action(CatTom cat, ArrayList<sample.DrawItems> items) {

        int tx = cat.getX() + 2;
        int ty = cat.getY() - 2;

        cat.tryStep(tx, ty, items);
    }
}