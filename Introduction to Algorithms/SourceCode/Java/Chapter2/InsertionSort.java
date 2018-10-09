/**
 * Copyright © 1998-2018, TheFxkHive. All Rights Reserved.
 */
package Chapter2;

/**
 * 插入排序
 * <pre>
 * Modify Information:
 * Author       Date          Description
 * ============ ============= ============================
 * lancelee     2018年10月9日  Create this file
 * </pre>
 */
public class InsertionSort {

    /**
     * <p>插入排序</p>
     * @param arr 需要排序的元素
     * @return 有序的元素
     */
    public static int[] insertionSort(int[] arr) {
        for (int i = 1, len = arr.length; i < len; i++) {
            int value = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > value) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = value;
        }
        return arr;
    }
}