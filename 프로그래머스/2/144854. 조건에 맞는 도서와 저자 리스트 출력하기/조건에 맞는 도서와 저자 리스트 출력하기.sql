-- 코드를 입력하세요
SELECT b.BOOK_ID, a.AUTHOR_NAME, date_format(b.PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE
from BOOK b, AUTHOR a
where a.author_id = b.author_id and b.category='경제'
order by b.published_date;
