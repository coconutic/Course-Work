package CatStrategies;

import sample.DrawItems;

import java.util.ArrayList;

/**
 * Created by katrin on 4/6/16.
 */
public class CalmStrategy implements Strategy {

    private boolean Move;

    public CalmStrategy(){
        Move = true;
    }

    @Override
    public void Action(sample.CatTom cat, ArrayList<sample.DrawItems> items) {
        if (Move)
        {
            move1(cat, items);
        } else
        {
            move2(cat, items);
        }
    }
    public void move1(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        int dx = 0;
        int dy = 0;

        int point2X = 300;
        int point2Y = 100;
        int point3X = 300;
        int point3Y = 500;

        if ((cat.getY() == point2Y) && (cat.getX() > point2X))
        {
            dx -= 4;
        } else
        if ((cat.getX() == point3X) && (cat.getY() < point3Y))
        {
            dy += 4;
        }

        cat.tryStep(cat.getX() + dx, cat.getY(), items);
        cat.tryStep(cat.getX(), cat.getY() + dy, items);

        if ((cat.getX() == point3X) && (cat.getY() == point3Y))
        {
            Move = false;
        }
    }

    public void move2(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        int dx = 0;
        int dy = 0;

        int point1X = 500;
        int point2X = 300;
        int point2Y = 100;
        int point3X = 300;
        int point3Y = 500;

        if ((cat.getY() == point2Y) && (cat.getX() < point1X))
        {
            dx += 4;
        }
        if ((cat.getX() == point3X) && (cat.getY() > point2Y))
        {
            dy -= 4;
        }

        cat.tryStep(cat.getX() + dx, cat.getY(), items);
        cat.tryStep(cat.getX(), cat.getY() + dy, items);

        if ((cat.getX() == point1X) && (cat.getY() == point2Y))
        {
            Move = true;
        }
    }
}
