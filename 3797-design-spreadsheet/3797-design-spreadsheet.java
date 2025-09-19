class Spreadsheet {
    int[][] sheet;

    public Spreadsheet(int rows) {
        sheet = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int j = Character.toLowerCase(cell.charAt(0)) - 'a';
        int i = 0;
        for(int k=1; k<cell.length(); k++) {
            int d = Character.getNumericValue(cell.charAt(k));
            i = i * 10 + d;
        }
        i--; // zero based index
        sheet[i][j] = value;
    }
    
    public void resetCell(String cell) {
        int j = Character.toLowerCase(cell.charAt(0)) - 'a';
        int i = 0;
        for(int k=1; k<cell.length(); k++) {
            int d = Character.getNumericValue(cell.charAt(k));
            i = i * 10 + d;
        }
        i--; // zero based index
        sheet[i][j] = 0;
    }
    
    public int getValue(String formula) {
        int n = formula.length();
        int num1 = 0, num2 = 0;
        int row = 0, col = 0;
        int i = 1;

        if(!Character.isDigit(formula.charAt(i))) {
            col = Character.toLowerCase(formula.charAt(i)) - 'a';
            i++;
            while(formula.charAt(i) != '+') {
                int d = Character.getNumericValue(formula.charAt(i));
                row = row * 10 + d;
                i++;
            }
            row--;
            num1 = sheet[row][col];
        } else {
            while(formula.charAt(i) != '+') {
                int d = Character.getNumericValue(formula.charAt(i));
                num1 = num1 * 10 + d;
                i++;
            }
        }

        i++;
        row = 0; col = 0;

        if(!Character.isDigit(formula.charAt(i))) {
            col = Character.toLowerCase(formula.charAt(i)) - 'a';
            i++;
            while(i < n) {
                int d = Character.getNumericValue(formula.charAt(i));
                row = row * 10 + d;
                i++;
            }
            row--;
            num2 = sheet[row][col];
        } else {
            while(i < n) {
                int d = Character.getNumericValue(formula.charAt(i));
                num2 = num2 * 10 + d;
                i++;
            }
        }

        return num1 + num2;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */