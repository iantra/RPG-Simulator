
#ifndef ACTOR_SAVE_DATA
#	error please define ACTOR_SAVE_DATA in the format <name_of_class>, <name_of_parent_class>, savedval1, savedval2, savedval2, ...
#endif

#if BOOST_PP_VARIADIC_SIZE(ACTOR_SAVE_DATA) >= 1

#	define BOOST_PP_LOCAL_LIMITS (2, BOOST_PP_VARIADIC_SIZE(ACTOR_SAVE_DATA) - 1)

#	define CLASS_NAME BOOST_PP_VARIADIC_ELEM(0, ACTOR_SAVE_DATA)
#	define PARENT_NAME BOOST_PP_VARIADIC_ELEM(1, ACTOR_SAVE_DATA)

template<typename Archive>
void CLASS_NAME::serialize(Archive& ar, const unsigned int version)
{
	ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(PARENT_NAME);

#	define BOOST_PP_LOCAL_MACRO(n)\
			ar & BOOST_SERIALIZATION_NVP(BOOST_PP_VARIADIC_ELEM(n, ACTOR_SAVE_DATA)); \
		/**/

#	include BOOST_PP_LOCAL_ITERATE()

}

// IF YOU GET A COMPILE TIME ERROR HERE, YOU FORGOT TO PLACE THE INIT_SAVED_CLASS MACRO IN THE BEGINNING OF THE CLASS
template void CLASS_NAME::serialize<>(boost::archive::polymorphic_oarchive&, const unsigned int version);
template void CLASS_NAME::serialize<>(boost::archive::polymorphic_iarchive&, const unsigned int version);


// Make sure MODULE_NAME is defined
#	ifndef MODULE_NAME
#		error MODULE_NAME undefined -- it must be defined
#	endif


BOOST_CLASS_EXPORT_GUID(BOOST_PP_VARIADIC_ELEM(0, ACTOR_SAVE_DATA), BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_STRINGIZE(MODULE_NAME), BOOST_PP_STRINGIZE(.)), BOOST_PP_STRINGIZE(BOOST_PP_VARIADIC_ELEM(0, ACTOR_SAVE_DATA))))


#	undef CLASS_NAME
#	undef PARENT_NAME

#endif


#undef ACTOR_SAVE_DATA