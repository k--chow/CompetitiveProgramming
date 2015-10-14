
/**
 * Write a description of class EightRooks here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class EightRooks
{
    public String isCorrect(String[] board)
    {
        String answer = "";
        int counter = 0;
        boolean outerloop = true;
        for(int r=0; r<8 && outerloop; r++)
        {
            int index = board[r].indexOf("R");
            if (index == -1)
            {
                answer = "Incorrect";
                break;
            }
            else
            {
                counter++;
                //check same row
                if (board[r].substring(index+1).indexOf("R") != -1)
                {
                    answer = "Incorrect";
                    break;
                }
            }
            //check column
            for(int c= r+1; c<8; c++)
            {
                if (index == board[c].indexOf("R"))
                {
                    answer = "Incorrect";
                    outerloop = false;
                    break;
                }
            }
        }
        
        if (counter == 8 && outerloop)
        {
            answer = "Correct";
        }
        return answer;
    }
}
