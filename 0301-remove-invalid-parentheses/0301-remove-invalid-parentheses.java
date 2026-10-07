class Solution {

    private Set<String> validExpressions = new HashSet<String>();
    private int minimumRemoved;

    private void reset() {
        this.validExpressions.clear();
        this.minimumRemoved = Integer.MAX_VALUE;
    }

    private void recurse(
            String s,
            int index,
            int leftCount,
            int rightCount,
            StringBuilder expression,
            int removedCount) {

        // If we have reached the end of string.
        if (index == s.length()) {

            // If the current expression is valid.
            if (leftCount == rightCount) {

                // If the current count of removed parentheses is <= the current minimum count
                if (removedCount <= this.minimumRemoved) {

                    // Convert StringBuilder to a String. This is an expensive operation.
                    // So we only perform this when needed.
                    String possibleAnswer = expression.toString();

                    // If the current count beats the overall minimum we have till now
                    if (removedCount < this.minimumRemoved) {
                        this.validExpressions.clear();
                        this.minimumRemoved = removedCount;
                    }
                    this.validExpressions.add(possibleAnswer);
                }
            }
        } else {

            char currentCharacter = s.charAt(index);
            int length = expression.length();

            // If the current character is neither an opening bracket nor a closing one,
            // simply recurse further by adding it to the expression StringBuilder
            if (currentCharacter != '(' && currentCharacter != ')') {
                expression.append(currentCharacter);
                this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
                expression.deleteCharAt(length);
            } else {

                // Recursion where we delete the current character and move forward
                this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);
                expression.append(currentCharacter);

                // If it's an opening parenthesis, consider it and recurse
                if (currentCharacter == '(') {
                    this.recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
                } else if (rightCount < leftCount) {
                    // For a closing parenthesis, only recurse if right < left
                    this.recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
                }

                // Undoing the append operation for other recursions.
                expression.deleteCharAt(length);
            }
        }
    }

    public List<String> removeInvalidParentheses(String s) {

        this.reset();
        this.recurse(s, 0, 0, 0, new StringBuilder(), 0);
        return new ArrayList(this.validExpressions);
    }
}

// class Solution {
//     public List<String> removeInvalidParentheses(String s) {
//         HashSet<String> validStrings = new HashSet<>();
//         int[] maxSize = new int[] { Integer.MIN_VALUE };

//         generateAllValidStrings(0, s, "", validStrings, maxSize);

//         return validStrings.stream()
//                 .filter(str -> str.length() == maxSize[0])
//                 .collect(Collectors.toList());
//     }

//     private void generateAllValidStrings(int i, String s, String temp, HashSet<String> validStrings, int[] maxSize) {
//         int n = s.length();

//         if (i == n) {
//             if (isValid(temp)) {
//                 validStrings.add(temp);
//                 maxSize[0] = Math.max(maxSize[0], temp.length());
//             }

//             return;
//         }

//         generateAllValidStrings(i + 1, s, temp + s.charAt(i), validStrings, maxSize);
//         generateAllValidStrings(i + 1, s, temp, validStrings, maxSize);
//     }

//     private boolean isValid(String s) {
//         int open = 0;

//         for (char ch : s.toCharArray()) {
//             if (ch == '(') {
//                 open++;
//             } else if (ch == ')') {
//                 if (open > 0) {
//                     open--;
//                 } else {
//                     return false;
//                 }
//             }
//         }

//         return open == 0;
//     }
// }