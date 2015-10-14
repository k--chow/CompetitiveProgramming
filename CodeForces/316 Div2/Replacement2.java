import java.util.*;
import java.io.*;
public class Replacement2
{
    public static void main(String [] args)
    {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        int N = in.nextInt();
        int M = in.nextInt();
        char[] s = in.readString().toCharArray();
        int ans = 0;
        int now = 0;
        for (int i=0; i<N;i++)
        {
            if (s[i] == '.')
            {
                now++;
                if (i == N-1)
                {
                    ans+=now-1;
                }
            }
            else
            {
                if (now >0)
                {
                ans+=now-1;
                now = 0;
                }
            }
            
        }//count success!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        
        while (M-->0)
        {
            int place = in.nextInt()-1;
            char r = in.readString().charAt(0);
            if (r == '.')//adding good
            {
                if (s[place] != '.')
                {
                    if (place-1>= 0 && s[place-1] == '.') ans++;
                    if (place+1 < N && s[place+1] == '.') ans++;
                }
            }
            else //adding bad
            {
                if (s[place] == '.')
                {
                    if (place-1 >= 0 && s[place-1] == '.') ans--;
                    if (place+1 < N && s[place+1] == '.') ans--;
                }
            }
            s[place] = r;
            System.out.println(ans);
        }
        
        
        
    }
    
    static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
