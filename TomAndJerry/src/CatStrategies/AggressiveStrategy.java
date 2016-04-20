package CatStrategies;

import sample.DrawItems;
import sample.MouseJerry;

import java.util.ArrayList;

/**
 * Created by katrin on 4/6/16.
 */
public class AggressiveStrategy implements Strategy {

    @Override
    public void Action(sample.CatTom cat, ArrayList<sample.DrawItems> items) {

        for (sample.DrawItems obj : items){
            if (obj instanceof sample.MouseJerry){
                forward((MouseJerry) obj, cat, items);
                break;
            }
        }
    }

    public  void forward(sample.MouseJerry mim, sample.CatTom cat, ArrayList<sample.DrawItems> items){
        int dx = 0;
        int dy = 0;

        if (cat.getX() > mim.getX()){
            dx -= 4;
        } else
        if (cat.getX() < mim.getX()){
            dx += 4;
        }

        if (cat.getY() > mim.getY()){
            dy -= 4;
        } else
        if (cat.getY() < mim.getY()){
            dy += 4;
        }

        cat.tryStep(cat.getX() + dx, cat.getY(), items);
        cat.tryStep(cat.getX(), cat.getY() + dy, items);
    }
}
