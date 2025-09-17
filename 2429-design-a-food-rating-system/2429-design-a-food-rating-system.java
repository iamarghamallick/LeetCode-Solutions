class FoodRatings {
    static class Food implements Comparable<Food> {
        String name;
        int rating;
        Food(String name, int rating) {
            this.name = name;
            this.rating = rating;
        }
        public int compareTo(Food other) {
            if (this.rating != other.rating) return other.rating - this.rating; // higher rating first
            return this.name.compareTo(other.name); // lexicographically smaller first
        }
    }

    Map<String, String> foodCuisine = new HashMap<>();
    Map<String, Food> foodMap = new HashMap<>();
    Map<String, TreeSet<Food>> cuisineMap = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            Food food = new Food(foods[i], ratings[i]);
            foodCuisine.put(foods[i], cuisines[i]);
            foodMap.put(foods[i], food);
            cuisineMap.computeIfAbsent(cuisines[i], k -> new TreeSet<>()).add(food);
        }
    }

    public void changeRating(String food, int newRating) {
        String cuisine = foodCuisine.get(food);
        Food oldFood = foodMap.get(food);
        cuisineMap.get(cuisine).remove(oldFood); // remove old entry
        Food newFood = new Food(food, newRating);
        foodMap.put(food, newFood);
        cuisineMap.get(cuisine).add(newFood); // add updated entry
    }

    public String highestRated(String cuisine) {
        return cuisineMap.get(cuisine).first().name; // top element
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */