-- 코드를 입력하세요
SELECT info.REST_ID, rest_name, food_type, favorites, address, round(avg(review.review_score), 2) as score
from rest_info info, rest_review review
where info.rest_id = review.rest_id and info.address like '서울%'
group by rest_id
order by score desc, favorites desc;