-- 코드를 입력하세요
SELECT ri.FOOD_TYPE, ri.REST_ID, ri.REST_NAME, ri.FAVORITES
FROM (
    SELECT FOOD_TYPE, MAX(FAVORITES) as maxi
    FROM REST_INFO
    GROUP BY FOOD_TYPE
    ) as filtered
JOIN REST_INFO ri
ON ri.FOOD_TYPE = filtered.FOOD_TYPE
WHERE ri.FAVORITES = maxi
ORDER BY FOOD_TYPE desc