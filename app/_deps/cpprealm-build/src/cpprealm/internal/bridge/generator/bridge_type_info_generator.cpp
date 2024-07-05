#if defined(_MSC_VER)
#define _WINSOCKAPI_
#endif

#include "realm.hpp"
#include "realm/object-store/shared_realm.hpp"
#include "realm/object-store/dictionary.hpp"
#include "realm/object-store/list.hpp"
#include "realm/object-store/results.hpp"
#include "realm/object-store/thread_safe_reference.hpp"
#include "realm/object-store/sync/app.hpp"
#include "realm/sync/config.hpp"
#include "realm/sync/subscriptions.hpp"


#undef KEY
#if defined(__i386)
# define KEY '_','_','i','3','8','6'
#elif defined(__x86_64)
# define KEY '_','_','x','8','6','_','6','4'
#elif defined(__ppc__)
# define KEY '_','_','p','p','c','_','_'
#elif defined(__ppc64__)
# define KEY '_','_','p','p','c','6','4','_','_'
#elif defined(__aarch64__)
# define KEY '_','_','a','a','r','c','h','6','4','_','_'
#elif defined(__ARM_ARCH_7A__)
# define KEY '_','_','A','R','M','_','A','R','C','H','_','7','A','_','_'
#elif defined(__ARM_ARCH_7S__)
# define KEY '_','_','A','R','M','_','A','R','C','H','_','7','S','_','_'
#endif

int main()
{
    int required = 0;

    #define REALM_TYPE_INFO(NAME, EXPRESSION, ...) \
        static char info_##NAME[] =  {'R', 'E', 'A', 'L', 'M', '_', 'T', 'Y', 'P', 'E', '_', 'I', 'N', 'F', 'O', ':', __VA_ARGS__,'[', \
        ('0' + ((sizeof(EXPRESSION) / 10000)%10)), \
        ('0' + ((sizeof(EXPRESSION) / 1000)%10)), \
        ('0' + ((sizeof(EXPRESSION) / 100)%10)), \
        ('0' + ((sizeof(EXPRESSION) / 10)%10)), \
        ('0' +  (sizeof(EXPRESSION)    % 10)), \
        ',', \
        ('0' + ((alignof(EXPRESSION) / 10000)%10)), \
        ('0' + ((alignof(EXPRESSION) / 1000)%10)), \
        ('0' + ((alignof(EXPRESSION) / 100)%10)), \
        ('0' + ((alignof(EXPRESSION) / 10)%10)), \
        ('0' +  (alignof(EXPRESSION)    % 10)), \
        ']', \
        '\0'}; \
        required += info_##NAME[0]

    REALM_TYPE_INFO(OwnedBinaryData, realm::OwnedBinaryData, 'O', 'w', 'n', 'e', 'd', 'B', 'i', 'n', 'a', 'r', 'y', 'D', 'a', 't', 'a');
;REALM_TYPE_INFO(Realm_Config, realm::Realm::Config, 'R', 'e', 'a', 'l', 'm', '_', 'C', 'o', 'n', 'f', 'i', 'g');
;REALM_TYPE_INFO(ColKey, realm::ColKey, 'C', 'o', 'l', 'K', 'e', 'y');
;REALM_TYPE_INFO(Decimal128, realm::Decimal128, 'D', 'e', 'c', 'i', 'm', 'a', 'l', '1', '2', '8');
;REALM_TYPE_INFO(Dictionary, realm::object_store::Dictionary, 'D', 'i', 'c', 't', 'i', 'o', 'n', 'a', 'r', 'y');
;REALM_TYPE_INFO(CoreDictionary, realm::Dictionary, 'C', 'o', 'r', 'e', 'D', 'i', 'c', 't', 'i', 'o', 'n', 'a', 'r', 'y');
;REALM_TYPE_INFO(List, realm::List, 'L', 'i', 's', 't');
;REALM_TYPE_INFO(LnkLst, realm::LnkLst, 'L', 'n', 'k', 'L', 's', 't');
;REALM_TYPE_INFO(Mixed, realm::Mixed, 'M', 'i', 'x', 'e', 'd');
;REALM_TYPE_INFO(ObjKey, realm::ObjKey, 'O', 'b', 'j', 'K', 'e', 'y');
;REALM_TYPE_INFO(ObjLink, realm::ObjLink, 'O', 'b', 'j', 'L', 'i', 'n', 'k');
;REALM_TYPE_INFO(Obj, realm::Obj, 'O', 'b', 'j');
;REALM_TYPE_INFO(ObjectId, realm::ObjectId, 'O', 'b', 'j', 'e', 'c', 't', 'I', 'd');
;REALM_TYPE_INFO(ObjectSchema, realm::ObjectSchema, 'O', 'b', 'j', 'e', 'c', 't', 'S', 'c', 'h', 'e', 'm', 'a');
;REALM_TYPE_INFO(Object, realm::Object, 'O', 'b', 'j', 'e', 'c', 't');
;REALM_TYPE_INFO(IndexSet, realm::IndexSet, 'I', 'n', 'd', 'e', 'x', 'S', 'e', 't');
;REALM_TYPE_INFO(CollectionChangeSet, realm::CollectionChangeSet, 'C', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', 'C', 'h', 'a', 'n', 'g', 'e', 'S', 'e', 't');
;REALM_TYPE_INFO(IndexSet_IndexIterator, realm::IndexSet::IndexIterator, 'I', 'n', 'd', 'e', 'x', 'S', 'e', 't', '_', 'I', 'n', 'd', 'e', 'x', 'I', 't', 'e', 'r', 'a', 't', 'o', 'r');
;REALM_TYPE_INFO(IndexSet_IndexIteratableAdaptor, realm::IndexSet::IndexIteratableAdaptor, 'I', 'n', 'd', 'e', 'x', 'S', 'e', 't', '_', 'I', 'n', 'd', 'e', 'x', 'I', 't', 'e', 'r', 'a', 't', 'a', 'b', 'l', 'e', 'A', 'd', 'a', 'p', 't', 'o', 'r');
;REALM_TYPE_INFO(NotificationToken, realm::NotificationToken, 'N', 'o', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', 'T', 'o', 'k', 'e', 'n');
;REALM_TYPE_INFO(Property, realm::Property, 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y');
;REALM_TYPE_INFO(Query, realm::Query, 'Q', 'u', 'e', 'r', 'y');
;REALM_TYPE_INFO(Results, realm::Results, 'R', 'e', 's', 'u', 'l', 't', 's');
;REALM_TYPE_INFO(Schema, realm::Schema, 'S', 'c', 'h', 'e', 'm', 'a');
;REALM_TYPE_INFO(Set, realm::object_store::Set, 'S', 'e', 't');
;REALM_TYPE_INFO(SyncError, realm::SyncError, 'S', 'y', 'n', 'c', 'E', 'r', 'r', 'o', 'r');
;REALM_TYPE_INFO(TableRef, realm::TableRef, 'T', 'a', 'b', 'l', 'e', 'R', 'e', 'f');
;REALM_TYPE_INFO(TableView, realm::TableView, 'T', 'a', 'b', 'l', 'e', 'V', 'i', 'e', 'w');
;REALM_TYPE_INFO(ThreadSafeReference, realm::ThreadSafeReference, 'T', 'h', 'r', 'e', 'a', 'd', 'S', 'a', 'f', 'e', 'R', 'e', 'f', 'e', 'r', 'e', 'n', 'c', 'e');
;REALM_TYPE_INFO(Timestamp, realm::Timestamp, 'T', 'i', 'm', 'e', 's', 't', 'a', 'm', 'p');
;REALM_TYPE_INFO(UUID, realm::UUID, 'U', 'U', 'I', 'D');
;REALM_TYPE_INFO(Status, realm::Status, 'S', 't', 'a', 't', 'u', 's');
;REALM_TYPE_INFO(ErrorCategory, realm::ErrorCategory, 'E', 'r', 'r', 'o', 'r', 'C', 'a', 't', 'e', 'g', 'o', 'r', 'y');
;REALM_TYPE_INFO(AppCredentials, realm::app::AppCredentials, 'A', 'p', 'p', 'C', 'r', 'e', 'd', 'e', 'n', 't', 'i', 'a', 'l', 's');
;REALM_TYPE_INFO(AppError, realm::app::AppError, 'A', 'p', 'p', 'E', 'r', 'r', 'o', 'r');
;REALM_TYPE_INFO(SyncSubscriptionSet, realm::sync::SubscriptionSet, 'S', 'y', 'n', 'c', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n', 'S', 'e', 't');
;REALM_TYPE_INFO(MutableSyncSubscriptionSet, realm::sync::MutableSubscriptionSet, 'M', 'u', 't', 'a', 'b', 'l', 'e', 'S', 'y', 'n', 'c', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n', 'S', 'e', 't');


    return required;
}
