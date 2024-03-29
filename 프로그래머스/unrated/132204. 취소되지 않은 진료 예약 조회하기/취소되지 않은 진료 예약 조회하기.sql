-- 코드를 입력하세요
SELECT ap.APNT_NO, pt.PT_NAME, pt.PT_NO, ap.MCDP_CD, dr.DR_NAME, ap.APNT_YMD
FROM PATIENT pt
JOIN DOCTOR dr
JOIN APPOINTMENT ap
ON pt.PT_NO = ap.PT_NO and ap.MDDR_ID = dr.DR_ID
WHERE LEFT(ap.APNT_YMD, 10) = "2022-04-13" and ap.APNT_CNCL_YN = "N"
ORDER BY ap.APNT_YMD