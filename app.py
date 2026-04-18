import os
from dotenv import load_dotenv
from openai import OpenAI

load_dotenv()

client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

def read_file(path):
    with open(path, "r", encoding="utf-8") as f:
        return f.read()

def analyze(resume, job):
    prompt = f"""
You are a software engineering hiring assistant.

Compare this resume to the job description.

Return:
1. Match summary
2. Strengths
3. Missing skills
4. Suggestions to improve the resume

Resume:
{resume}

Job:
{job}
"""

    response = client.chat.completions.create(
        model="gpt-4o-mini",
        messages=[{"role": "user", "content": prompt}],
        temperature=0.3
    )

    return response.choices[0].message.content

if __name__ == "__main__":
    resume = read_file("sample_resume.txt")
    job = read_file("sample_job.txt")

    print("\nAnalyzing...\n")
    result = analyze(resume, job)

    print("=== RESULT ===\n")
    print(result)