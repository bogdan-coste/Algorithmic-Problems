import java.util.*;

public class Main {

    public static List<String> fullJustify(String[] words, int maxWidth) {

        int wordIndex = 0;
        int totalWords = words.length;
        List<String> result = new ArrayList<>(10);

        StringBuilder sb = new StringBuilder(maxWidth);

        while (wordIndex < totalWords) {

            // --- PHASE 1: Gather words for the current line ---
            int lookaheadOffset = 0;
            int charCount = 0;
            int lineWordCount = 0;

            while (wordIndex + lookaheadOffset < totalWords) {
                if (charCount + (lineWordCount - 1) + words[wordIndex + lookaheadOffset].length() < maxWidth) {
                    charCount += words[wordIndex + lookaheadOffset].length();
                    lookaheadOffset++;
                    lineWordCount++;
                } else {
                    break;
                }
            }

            // --- PHASE 2: Calculate space requirements ---
            boolean isLastLine = (wordIndex + lineWordCount) == totalWords;
            int spaceGaps = lineWordCount > 1 ? (lineWordCount - 1) : 1;
            int totalSpaces = maxWidth - charCount;

            // --- PHASE 3: Build the string ---
            int wordOffset = 0;

            if (!isLastLine && lineWordCount > 1) {

                // Fully Justified Line
                if (totalSpaces % spaceGaps != 0) {

                    // Uneven space distribution
                    int largeSpaceSize = totalSpaces / spaceGaps + 1;
                    int largeSpaceCount = totalSpaces % spaceGaps;
                    int smallSpaceCount = spaceGaps - largeSpaceCount;
                    int smallSpaceSize = (totalSpaces - largeSpaceCount * largeSpaceSize) / smallSpaceCount;

                    for (int j = 0; j < largeSpaceCount; j++) {
                        sb.append(words[wordIndex + wordOffset]);
                        sb.append(" ".repeat(largeSpaceSize));
                        wordOffset++;
                    }

                    for (int j = 0; j < smallSpaceCount; j++) {
                        sb.append(words[wordIndex + wordOffset]);
                        sb.append(" ".repeat(smallSpaceSize));
                        wordOffset++;
                    }

                } else {

                    int evenGapCount = spaceGaps;
                    int evenSpaceSize = totalSpaces / evenGapCount;

                    for (int j = 0; j < evenGapCount; j++) {
                        sb.append(words[wordIndex + wordOffset]);
                        sb.append(" ".repeat(evenSpaceSize));
                        wordOffset++;
                    }
                }

                // Append the final word of the line (applies to both even and uneven spacing)
                sb.append(words[wordIndex + wordOffset]);
                result.add(sb.toString());

            } else {

                // Left Justified Line (last line or single-word line)
                for (int j = 0; j < lineWordCount - 1; j++) {
                    sb.append(words[wordIndex + wordOffset]);
                    sb.append(" ");
                    wordOffset++;
                }

                sb.append(words[wordIndex + wordOffset]);
                sb.append(" ".repeat((totalSpaces - (lineWordCount - 1))));

                result.add(sb.toString());
            }

            wordIndex += lineWordCount;
            sb.setLength(0);
        }

        return result;
    }

    public static void main(String[] args) {

        String[] text = {"This", "is", "an", "example", "of", "text", "justification."};
        System.out.println(fullJustify(text, 16));
    }

}
