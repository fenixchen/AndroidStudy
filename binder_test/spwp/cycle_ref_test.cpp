#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
using namespace android;


class Student;

class Teacher : public RefBase
{
    private:
        String8 m_name;
        sp<Student> m_student;
    public:
        Teacher(const char *name):
            m_name(name)
        {                        
            printf("Call %s();\n", __FUNCTION__);
        }
        ~Teacher()
        {
            printf("Call %s();\n", __FUNCTION__);
        }
        const char* name() const
        {
            return m_name;
        }
        void printRefCount()
        {
            int32_t strong = getStrongCount();
            int32_t weak = getWeakRefs()->getWeakCount();
            printf("Teacher, Strong:%x, Weak:%d\n", strong, weak);
        }
        void setStudent(Student *student)
        {
            m_student = student;
        }
};

class Student : public RefBase
{
    private:
        wp<Teacher> m_teacher;
    public:
        Student()
        {            
            printf("Call %s();\n", __FUNCTION__);
        }
        ~Student()
        {
            printf("Call %s();\n", __FUNCTION__);
        }
        void printRefCount()
        {
            int32_t strong = getStrongCount();
            int32_t weak = getWeakRefs()->getWeakCount();
            printf("Student, Strong:%x, Weak:%d\n", strong, weak);
        }        
        void setTeacher(Teacher *teacher)
        {
            m_teacher = teacher;            
        }        
        void printTeacherName()
        {
            sp<Teacher> t = m_teacher.promote();
            if (t.get())
            {
                printf("Teacher Name:%s\n", m_teacher.promote()->name());                        
            }
            else
            {
                printf("Teacher is released\n");
            }
        }
};

void test_cycle_ref()
{
    printf("\n\nCycle reference test!\n");
    {
        sp<Teacher> t = new Teacher("Wang");
        sp<Student> s = new Student();

        t->setStudent(s.get());
        s->setTeacher(t.get());

        s->printRefCount();
        t->printRefCount();

        s->printTeacherName();

        t.clear();

        s->printTeacherName();
        
    }
}
